emplate<class T>
class Shared_ptr
{
public:

	Shared_ptr(T *ptr)
		:_ptr(ptr)
		, _CountPtr(new int(1))//构造的时候，被一个管理起来
		, _mtx(new mutex)//初始化一把锁
	{}

	~Shared_ptr()
	{
		subRef();//加锁后的--操作
		//(*_CountPtr)--;

		if (*_CountPtr == 0)//为0时，表示没有管理的了
		{
			delete _ptr;
			delete _CountPtr;
			delete _mtx;
			cout << "~Shared_ptr()" << endl;
		}
	}

	Shared_ptr(const Shared_ptr<T> &sp)
		:_ptr(sp._ptr)
		, _CountPtr(sp._CountPtr)
		, _mtx(sp._mtx)
	{
		addRef();//加锁后的++操作
		//(*_CountPtr)++;
	}

	Shared_ptr<T> &operator=(const Shared_ptr<T> &sp)
	{
		//判断是不是管理的同一份资源
		if (_ptr != sp._ptr)
		{
			//if (--(*_CountPtr) == 0)//断开已经管理的资源
			if (subRef==0)
			{
				delete _ptr;//如果管理的资源没有其它人进行管理了，则释放掉
				delete _CountPtr;
				delete _mtx;
			}

			//赋值
			_ptr = sp._ptr;
			_CountPtr = sp._CountPtr;
			_mtx = sp._mtx;
			addRef();
		}

		return *this;
	}

	T& operator *()
	{
		return *_ptr;
	}

	T* operator ->()
	{
		return _ptr;
	}

	int GetCount()
	{
		return *_CountPtr;
	}

	int addRef()
	{
		_mtx->lock();
		(*_CountPtr)++;
		_mtx->unlock();

		return *_CountPtr;
	}

	int subRef()
	{
		_mtx->lock();
		(*_CountPtr)--;
		_mtx->unlock();

		return *_CountPtr;
	}

private:
	T *_ptr;
	int *_CountPtr;//通过指针，来控制管理同一份资源的，都指向同一块地址空间
	mutex *_mtx;//加上一把锁
};

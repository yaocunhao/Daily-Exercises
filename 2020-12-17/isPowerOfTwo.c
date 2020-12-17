给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

bool isPowerOfTwo(int n){
	//2的次方幂即二进制中只有一个1
	if (n <= 0)
		return  false;
	if (!(n&n - 1))
		return true;
	else
		return
		false;


}
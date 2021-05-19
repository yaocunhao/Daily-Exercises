#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int song;    
    string str;
    while(cin>>song>>str)//歌曲数量
    {
        int sub=1;//当前所处位置
        
        //begin、end表示列表的起始和终止位置
        int begin=1;
        int end;
        if(song>4)
            end=4;
        else//song<=4
            end=song;
        
        char choose;
        int i=0;
        
        while(i<str.size())//输入选择,将光标挪动对应的歌曲位置
        {
            choose=str[i];
            i++;
              if(song<=4)//不需要翻页
              {
                  if(choose=='U')
                  {
                      sub--;
                      if(sub==0)
                          sub=song;
                  }
                  else//down
                  {
                      sub++;
                      if(sub>song)
                          sub=1;
                  }
              }
            
              else//song>4,需要翻页
              {
                      if(choose=='U')
                      {
                              if(sub==1)//此时需要翻页
                              {
                                  sub=song;
                                  //显示的起始和终点位置
                                  begin=song-4+1;
                                  end=song;
                              }
                              else//不需要翻页
                              {
                                  sub--;
                                  if(sub<begin)//说明需要新的页面了
                                  {
                                      begin--;
                                      end--;
                                  }
                              }
                       }
                  else//down
                  {
                          if(sub==song)//需要翻页
                          {
                              sub=1;
                              begin=1;
                              end=4;
                          }
                          else//不需要翻页
                          {
                              sub++;
                              if(sub>end)
                              {
                                  begin++;
                                  end++;
                              }
                          }
                    }
              }
            
        }
        //选择完毕
        
          while(begin!=end)//输出列表内容
          {
              cout<<begin<<" ";
              begin++;
          }
        
          cout<<begin<<endl;
          cout<<sub<<endl;
 }

    return 0;
}
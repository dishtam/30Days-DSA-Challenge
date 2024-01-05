string encode(string src)
{     
  //Your code here 
  int n = src.size();
  string temp="";
  for(int i=0;i<n;i++){
      temp+=src[i];
      int cnt=1;
      while(i<n-1 && src[i]==src[i+1]){
          i++;
          cnt++;
      }
      temp+=cnt+'0';
  }
  return temp;
}   

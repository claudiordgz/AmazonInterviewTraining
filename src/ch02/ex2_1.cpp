void RemoveDuplicate(std::string &rhs)
{
  if(!rhs.empty()){
    int flag=0;
    for(std::size_t i=0; i!=rhs.size(); ++i){
      int offset = rhs.at(i) - 'a';
      offset = 1 << offset;
      if(flag & offset){
        rhs.erase(rhs.begin()+i);
        i--;
      }
      flag = flag | offset;
    }
  }
}
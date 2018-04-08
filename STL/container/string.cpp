
  vai ordenar os caracteres do container string..

  std::string str = "hello world";

  std::sort(str.begin(), str.end());

	for ( auto& i : v )
	{
      std::cout << i.c_str() << std::endl;
	}
   
  vai ordenar as palavras por ordem ...

  std::vector<std::string> str = { "rato", "gato", "vaca", "galinha", "coruja" }; 

  std::sort(str.begin(), str.end());

  for ( auto& i : v )
	{
      std::cout << i.c_str() << std::endl;
	}  

  

  
http://en.cppreference.com/w/cpp/string/basic_string/operator_cmp


vai ordenar os caracteres do container string..

std::string str1 = "Hello";
std::string str2 = "World";

// o operator> é sobrecarregado para receber 2 strings, uma comparação lexicografica é feita para descobrir qual
// string é menor
str1 < str2;

std::string str = "hello world";

// ordena os caracteres em ordem ascendente
std::sort(str.begin(), str.end()); 

for ( auto& i : v )
{
    std::cout << i.c_str() << std::endl;
}
   


std::vector<std::string> str = { "rato", "gato", "vaca", "galinha", "coruja" }; 

// ordena as palavras em ordem alfabética/léxicográfica
// operator< que é usado internamente é sobrecarregado para tratar de strings
std::sort(str.begin(), str.end());

for ( auto& i : v )
{
    std::cout << i.c_str() << std::endl;
}  
 
http://en.cppreference.com/w/cpp/string/basic_string/operator_cmp

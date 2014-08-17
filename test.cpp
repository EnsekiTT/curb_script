#include<iostream>
#include<boost/spirit/include/qi.hpp>
#include<boost/spirit/include/phoenix.hpp>
#include<boost/lexical_cast.hpp>

namespace qi=boost::spirit::qi;
namespace ascii=boost::spirit::ascii;

template<class Iterator>
struct calc : qi::grammar<Iterator,float(),ascii::space_type>{
    qi::rule<Iterator,float(),ascii::space_type> expr,term,fctr;
    
    calc():calc::base_type(expr)
    {
        expr = term[
                    qi::_val=qi::_1] >> *( ('+' >> term[qi::_val += qi::_1])
                                         | ('-' >> term[qi::_val -= qi::_1]) );
        
        term = fctr[
                    qi::_val=qi::_1] >> *( ('*' >> fctr[qi::_val*=qi::_1])
                                         | ('/' >> fctr[qi::_val/=qi::_1]) );/*[foo]*/
        
        fctr = qi::int_|'('>>expr>>')';
    }
    static void foo(){std::cout<<"Called foo"<<std::endl;}
};


int main()
{
    for(std::string str(""); std::cout<<">> ",
        std::getline(std::cin,str)&&!str.empty();){
        calc<std::string::iterator> c;
        std::string::iterator first(str.begin());
        float result=0;
        
        std::cout<<
            (qi::phrase_parse(
                              first,
                              str.end(),
                              c,
                              ascii::space,
                              result)
             ? boost::lexical_cast<std::string>(result).c_str()
             : "Error")
        <<std::endl;
    }
}
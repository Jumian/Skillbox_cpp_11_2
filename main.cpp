#include <iostream>

bool is_email(std::string email){
    std::string left="",right="";
    bool bLeft=true,bDot=false;
    for(int i = 0; i<email.length();i++){
        if (email[i]<'!' || email[i]>'['&& email[i]<']' || email[i]=='\"'||email[i]=='('||email[i]==')'){
            return false;
        }
        if (email[i]=='.' && bDot){
            return false;
        }
        else if (email[i]=='.' && !bDot) bDot = true;
        else if (email[i]!='.' && bDot) bDot=false;

        if (email[i]=='@'&& bLeft) bLeft=false;
        else if (email[i]=='@'&& !bLeft) {
            return false;
        }
        else (bLeft?left:right)+=email[i];
    }
    if (left.length()>64||right.length()>63||right.length()<=0||left.length()<=0){
        return false;
    }
    //std::cout << left<< " " << right<<std::endl;
    return true;
}

void test(std::string arg){
    std::cout << arg << std::endl;
    std::cout << (is_email(arg)?"Yes":"No")<<std::endl;
}
int main() {
    std::string str;
    std::cout << "Correct emails:"<<std::endl;
    test("simple@example.com");
    test("very.common@example.com");
    test("disposable.style.email.with+symbol@example.com");
    test("other.email-with-hyphen@example.com");
    test("fully-qualified-domain@example.com");
    test("user.name+tag+sorting@example.com");
    test("x@example.com");
    test("example-indeed@strange-example.com");
    test("admin@mailserver1");
    test("example@s.example");
    test("mailhost!username@example.org");
    test("user%example.com@example.org");
    std::cout << "Wrong emails:"<<std::endl;
    test("John..Doe@example.com");
    test("Abc.example.com");
    test("A@b@c@example.com");
    test("a\"b(c)d,e:f;g<h>i[j\\k]l@example.com");
    test("1234567890123456789012345678901234567890123456789012345678901234+x@example.com");
    test("i_like_underscore@but_its_not_allow_in _this_part.example.com");

    std::cout << "Email check:" << std::endl;
    std::cin >>str;
    std::cout << (is_email(str)?"Yes":"No");



    return 0;
}

#include <iostream>

class Integer{

    int *m_pInt;
public:
    Integer();
    //parameterized
    Integer(int value);
    //copy 
    Integer(const Integer &obj);
    //move
    Integer(Integer &&obj);

    int Getvalue()const;
    void Setvalue(int value);

    friend std::ostream & operator<<(std::ostream& stream, const Integer& integer);
    ~Integer();
};
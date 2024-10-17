#include "RPN.hpp"

bool    checkNumber(std::string const &token)
{
    for (std::string::const_iterator it = token.begin(); it != token.end(); ++it)
    {
        if (!isdigit(*it))
            return false;
        if (isdigit(*it) && it != token.end() && isdigit(*(it + 1)))
            return false;
    }
    return true;
}

void    run(char** argv)
{
    std::stack<int>     dataStack;
    std::stringstream   sstream(argv[1]);
    std::string         token;
    int                 m;
    int                 n;
    int                 number;

    while (sstream >> token)
    {
        if (token == "-" || token == "+" || token == "*" || token == "/")
        {
            if (dataStack.size() < 2) 
                throw std::runtime_error("Erreur : Pas assez d'opérandes pour l'opération");

            m = dataStack.top(); 
            dataStack.pop();
            n = dataStack.top(); 
            dataStack.pop();

            if (token == "+") 
                dataStack.push(n + m);
            else if (token == "-") 
                dataStack.push(n - m);
            else if (token == "/")
            {
                if (m == 0) 
                    throw std::runtime_error("Erreur : Division par zéro");
                dataStack.push(n / m);
            }
            else if (token == "*") 
                dataStack.push(n * m);
        }
        else
        {
            try
            {
                if (!checkNumber(token))
                    throw std::runtime_error("Error invlid number ==> " + token);
                number = std::stoi(token);
                dataStack.push(number); 
            }
            catch(const std::exception& e)
            {
                throw std::runtime_error("Erreur : Nombre invalide ==> " + token);
            }
        }
    }

    if (dataStack.size() != 1)
        throw std::runtime_error("Erreur : Trop de valeurs dans l'entrée");
    else
        std::cout << "Résultat : " << dataStack.top() << std::endl;
}
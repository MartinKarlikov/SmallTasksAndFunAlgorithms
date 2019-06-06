#include <iostream>
#include <string>
#include <vector>

int getFirstSubstrIndex(const std::string& toSearch, const std::string& toFind)
{

    std::vector<unsigned> startIndexes;

    for(size_t i = 0; i <= toSearch.size()-toFind.size(); ++i)
    {

        if(toSearch[i] == toFind[0] && toSearch[i+toFind.size()-1] == toFind[toFind.size()-1])
        {
            startIndexes.push_back(i);
        }

    }

    for(const unsigned& startIndex:startIndexes)
    {

            for(size_t i = 0; i < toFind.size(); ++i)
            {

                if(i == toFind.size()-1)
                {

                    return startIndex;

                }

                if(toSearch[startIndex+i] != toFind[i])
                {
                    break;
                }

            }

    }

    return -1;

}


int main()
{

    std::string input;
    std::string pattern;

    std::getline(std::cin,input);
    std::getline(std::cin,pattern);

    int ans = getFirstSubstrIndex(input,pattern);

    if(ans != -1)
    {
        std::cout << "The pattern has been found at index : "<<ans<<std::endl;
    }
    else
    {
        std::cout <<"Given pattern not found."<<std::endl;
    }

    return 0;
}

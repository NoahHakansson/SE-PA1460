#include <string>
#include <vector>
#include <iostream>

class interactionType {
protected:
    std::vector<std::string> optionList;
    std::string option = "";
    std::string optionConfirmation(std::string theOption) {
        for (int i = 0; i < this->optionList.size(); i++) {
            if (theOption == this->optionList[i]){
                this->option = theOption;
                return "SUCCESS";
            }
        }
        std::cout << this->optionList.size();
        return "FAILED";
    }
public:
    std::string virtual getName() = 0;
    std::string setOption(std::string theOption){
        std::string confirmationMessage = "";
        confirmationMessage = this->optionConfirmation(theOption);
        return confirmationMessage;
    }
};

class pickUpStrategy : public interactionType {
    protected: 
        std::vector<std::string> optionList = {"Gently", "Hard"};
    public:
        std::string getName() override {
            return "Pick up";
        }
};

class moveStrategy : public interactionType {
    protected: 
        std::vector<std::string> optionList = {"Gently", "Hard", "Barbaric"};
    public:
        std::string getName() override {
            return "Move it";
        }
};

class dropStrategy : public interactionType {
    protected: 
        std::vector<std::string> optionList = {"Gently", "Hard", "Nonchalant"};
    public:
        std::string getName() override {
            return "Drop it";
        }
};
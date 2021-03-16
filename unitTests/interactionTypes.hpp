#include <string>
#include <vector>
#include <iostream>

class interactionType
{
protected:
    std::vector<std::string> optionList = {};
    std::string option = "";
    std::string optionConfirmation(std::string theOption)
    {
        for (int i = 0; i < this->optionList.size(); i++)
        {
            if (theOption == this->optionList[i])
            {
                this->option = theOption;
                return "SUCCESS";
            }
        }
        std::cout << this->optionList.size();
        return "FAILED";
    }

public:
    std::string virtual getName() = 0;
    std::string virtual executeInteraction() = 0;
    std::string setOption(std::string theOption)
    {
        std::string confirmationMessage = "";
        confirmationMessage = this->optionConfirmation(theOption);
        return confirmationMessage;
    }
    std::string listOptions()
    {
        std::string returnList = "Options: ";
        for (int i = 0; i < optionList.size(); i++)
        {
            if (i < optionList.size() - 1)
            {
                returnList += (optionList[i] + ", ");
            }
            else
            {
                returnList += optionList[i];
            }
        }

        return returnList;
    }
    void unsetOption() {
        option = "";
    }
    std::string virtual executeInteraction()
    {
    }
};

class pickUpStrategy : public interactionType
{
protected:
public:
    pickUpStrategy() { optionList = {"Gently", "Hard"}; }
    std::string getName() override
    {
        return "Pick up";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You pick it up " + this->option;
        return interactionResponse;
    }
};

class moveStrategy : public interactionType
{
protected:
public:
    moveStrategy() { optionList = {"Gently", "Hard", "Barbaric"}; }
    std::string getName() override
    {
        return "Move it";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You move it " + this->option;
        return interactionResponse;
    }
};

class dropStrategy : public interactionType
{
protected:
public:
    dropStrategy() { optionList = {"Gently", "Hard", "Nonchalant"}; }
    std::string getName() override
    {
        return "Drop it";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You drop it " + this->option;
        return interactionResponse;
    }
};
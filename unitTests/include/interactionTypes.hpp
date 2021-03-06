#include <string>
#include <vector>

class interactionType
{
protected:
    std::vector<std::string> optionList = {};
    std::string option = "NULL";
    std::string optionConfirmation(std::string theOption)
    {
        this->unsetOption(); // reset on new try.
        for (int i = 0; i < this->optionList.size(); i++)
        {
            if (theOption == this->optionList[i])
            {
                this->option = theOption;
                return "SUCCESS";
            }
        }
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
        this->option = "NULL";
    }
    std::string getOption(){
        return this->option;
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
        if (this->option != "NULL"){
            std::string interactionResponse = "You pick it up " + this->option;
            return interactionResponse;
        }
        else {
            return "NO OPTION SET!";
        }
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
        if (this->option != ""){
            std::string interactionResponse = "You move it " + this->option;
            return interactionResponse;
        }
        else {
            return "NO OPTION SET!";
        }
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
        if (this->option != ""){
            std::string interactionResponse = "You drop it " + this->option;
            return interactionResponse;
        }
        else {
            return "NO OPTION SET!";
        }
    }
};

class lookStrategy : public interactionType
{
protected:
public:
    lookStrategy() { optionList = {"peek", "inspect"}; }
    std::string getName() override
    {
        return "Look at it";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You look at " + this->option;
        return interactionResponse;
    }
};

class openStrategy : public interactionType
{
protected:
public:
    openStrategy() { optionList = {"Gently", "Hard", "Barbaric"}; }
    std::string getName() override
    {
        return "Open it";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You open " + this->option;
        return interactionResponse;
    }
};

class TurnOnStrategy : public interactionType
{
protected:
public:
    TurnOnStrategy() { optionList = {"Gently", "Hard", "Nonchalant"}; }
    std::string getName() override
    {
        return "Turn it on";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You turn" + this->option + "on ";
        return interactionResponse;
    }
};

class TurnOffStrategy : public interactionType
{
protected:
public:
    TurnOffStrategy() { optionList = {"Gently", "Hard", "Nonchalant"}; }
    std::string getName() override
    {
        return "Turn it off";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You turn" + this->option + "off ";
        return interactionResponse;
    }
};

class TasteStrategy : public interactionType
{
protected:
public:
    TasteStrategy() { optionList = {"lick", "suckle", "gurgel"}; }
    std::string getName() override
    {
        return "Taste it";
    }

    std::string executeInteraction() override
    {
        std::string interactionResponse = "You taste" + this->option;
        return interactionResponse;
    }
};
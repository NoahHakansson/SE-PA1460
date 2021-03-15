#include <string>
#include <vector>

class interactionType {
protected:
    std::vector<std::string> OptionList;
    std::string option = "";
public:
    std::string virtual getName() = 0;
};

class pickUpStrategy : public interactionType {
    protected: 
        std::vector<std::string> OptionList = {"Gently", "Hard"};
    public:
        std::string getName() override {
            return "Pick up";
        }
};

class moveStrategy : public interactionType {
    protected: 
        std::vector<std::string> OptionList = {"Gently", "Hard", "Barbaric"};
    public:
        std::string getName() override {
            return "Move it";
        }
};

class dropStrategy : public interactionType {
    protected: 
        std::vector<std::string> OptionList = {"Gently", "Hard", "Nonchalant"};
    public:
        std::string getName() override {
            return "Drop it";
        }
};
#include <string>
#include <vector>

class ObjectState {
    protected:

    public:
        std::string virtual getState() = 0;
};

class MovedState: public ObjectState {
    protected:
    public:
        std::string getState()
        {
            return "Moved";
        }
};

class OnGroundState: public ObjectState {
    protected:
    public:
        std::string getState()
        {
            return "On ground";
        }
};

class PickedUpState: public ObjectState {
    protected:
    public:
        std::string getState()
        {
            return "Picked up";
        }
};
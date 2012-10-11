#include <iostream>
using namespace std;

const int MAX_FRIEND = 100;
class Player{
    public:
        enum {
            boy = 1,
            girl = 0
        };
        Player() : user_id_(0), user_sex_(boy){}
        ~Player(){}

        Player(const Player&);
        const Player& operator=(const Player&);

        void SetUserId(int user_id);
        int GetUserId() const;

        void SetGroupId(int group_id) const;
        int GetGroupId() const;

        void SetUserAge(int user_age) const;
        int GetUserAge() const;

        void SetUserName(const char* user_name);
        void PrintPlayerInfo() const;

    private:
        int user_id_;
        mutable int group_id_;
        int user_age_;
        string user_name_;
        const char user_sex_;
        static const int friend_count_ = MAX_FRIEND;
};

Player::Player(const Player& player):user_sex_(boy) {

}

const Player& Player::operator=(const Player& other) {

}

void Player::SetUserId(int user_id) {
    user_id_ = user_id;
}

int Player::GetUserId() const {
    return user_id_;
}

void Player::SetUserAge(int user_age) const {
    const_cast<Player*>(this)->user_age_ = user_age;
}

int Player::GetUserAge() const {
    return user_age_;
}
void Player::SetGroupId(int group_id) const {
    group_id_ = group_id;
}

int Player::GetGroupId() const {
    return group_id_;
}

void Player::SetUserName(const char* user_name) {
    user_name_ = user_name;
}

void Player::PrintPlayerInfo() const {
    cout<<"user id:\t"<<user_id_<<endl;
    cout<<"user name:\t"<<user_name_<<endl;
    cout<<"user sex:\t"<<user_sex_<<endl;
    cout<<"user age:\t"<<user_age_<<endl;
    cout<<"user group:\t"<<group_id_<<endl;
}
int main() {
    const Player player1;
    //player1.SetUserId(100001);
    player1.GetUserId();

    Player player2;

    player2.SetUserId(100001);

    player2.SetGroupId(100);

    player2.SetUserAge(21);

    player2.SetUserName("Jack");

    player2.PrintPlayerInfo();
    return 0;
}

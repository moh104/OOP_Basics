#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

[[nodiscard]] int get_intNumber(const std::string&);

class Skill
{
    public:
        Skill(const std::string& , int);

        [[nodiscard]] const std::string& get_name() const noexcept;
        [[nodiscard]] int get_level() const noexcept;
        
        void set_level(int);
        
        ~Skill() noexcept;

    private:
        std::string name;
        int level;
    
        void set_name(const std::string&);
    
        static constexpr int MIN_LEVEL{0};
        static constexpr int MAX_LEVEL{50};
};

class Character
{
    public:
        Character(const std::string& , int , int);

        void set_name(const std::string&);
        void set_health(int);
        void set_power(int);

        [[nodiscard]] std::string get_name() const noexcept;
        
        void add_skill(const std::string& , int);
        void remove_skill(const std::string& skillName);
        void print() const noexcept;
        void initialSkills();
        
        ~Character() noexcept;
        
    private:
        std::string name;
        int health;
        int power;
        std::vector<Skill> skills;
        
        [[nodiscard]] int find_index(const std::string& skillName) const noexcept;

        static constexpr int MIN_HEALTH{0};
        static constexpr int MAX_HEALTH{100};
        static constexpr int MIN_POWER{0};
        static constexpr int MAX_POWER{100};
};

#endif
#include <string>
#include <iostream>

using namespace std;

string marioArt ="                ************\n"
                 "               ####....#.\n"
                 "             #..###.....##....\n"
                 "             ###.......######              ###            ###\n"
                 "                ...........               #...#          #...#\n"
                 "               ##*#######                 #.#.#          #.#.#\n"
                 "            ####*******######             #.#.#          #.#.#\n"
                 "           ...#***.****.*###....          #...#          #...#\n"
                 "           ....**********##.....           ###            ###\n"
                 "           ....****    *****....\n"
                 "             ####        ####\n"
                 "           ######        ######\n"
                 "##############################################################\n"
                 "#...#......#.##...#......#.##...#......#.##------------------#\n"
                 "###########################################------------------#\n"
                 "#..#....#....##..#....#....##..#....#....#####################\n"
                 "##########################################    #----------#\n"
                 "#.....#......##.....#......##.....#......#    #----------#\n"
                 "##########################################    #----------#\n";
class Position {
public:
    float x, y;

    Position() : x(0), y(0) {}

    Position(float x, float y) : x(x), y(y) {}
};


class Platform {
public:
    Position position;
    int length;

    Platform() : position(), length(0) {}

    Platform(const Position &pos, int l) : position(pos), length(l) {}
};

class MainCharacter {
public:
    Position position;

    MainCharacter() : position() {}

    explicit MainCharacter(const Position &pos) : position(pos) {}
};

class Enemy {
public:
    Position position;

    Enemy() : position() {}

    explicit Enemy(const Position &pos) : position(pos) {}
//    explicit Enemy(const Position& pos) {
//        this->position = pos;
//    }
};

class Level {
public:
    Platform platform;
    MainCharacter mainCharacter;
    Enemy enemy;
};

class LevelBuilder {
public:

    virtual void createPlatform(const Position &pos, int length) = 0;

    virtual void createCharacter(const Position &pos) = 0;

    virtual void createEnemy(const Position &pos) = 0;

    virtual Level *getLevel() = 0;

    virtual void print(){};
};

class MarioLevel : public Level {
public:
    //default
//    MarioLevel() {
//        this->platform = Platform(Position(1, 1), 100) ;
//        this->mainCharacter = MainCharacter(Position(10, 1)) ;
//        this->enemy = Enemy(Position(40, 1)) ;
//    }
};

class AladinLevel : public Level {
};

class MarioLevelBuilder : public LevelBuilder {
public:
    MarioLevel *level;

    MarioLevelBuilder() {
        this->level = new MarioLevel();
    }

    Level *getLevel() override {
        return this->level;
    }

    void createPlatform(const Position &pos, int length) override {
        this->level->platform = Platform(pos, length);
        cout << "platform starts at: " << pos.x << ", " << pos.y << endl;
    }

    void createCharacter(const Position &pos) override {
        this->level->mainCharacter = MainCharacter(pos);
        cout << "mario at: " << pos.x << ", " << pos.y << endl;
    }

    void createEnemy(const Position &pos) override {
        this->level->enemy = Enemy(pos);
        cout << "enemy at: " << pos.x << ", " << pos.y << endl;
    };
    void print() override {
        cout << "Mario game:\n " << marioArt<< endl;
    }
};

class AladinLevelBuilder : public LevelBuilder {
public:
    AladinLevel *level;

    AladinLevelBuilder() {
        this->level = new AladinLevel();
    }

    Level *getLevel() override {
        return this->level;
    }

    void createPlatform(const Position &pos, int length) override {
        this->level->platform = Platform(pos, length);
        cout << "platform starts at: " << pos.x << ", " << pos.y << endl;
    }

    void createCharacter(const Position &pos) override {
        this->level->mainCharacter = MainCharacter(pos);
        cout << "Aladdin at: " << pos.x << ", " << pos.y << endl;
    }

    void createEnemy(const Position &pos) override {
        this->level->enemy = Enemy(pos);
        cout << "enemy at: " << pos.x << ", " << pos.y << endl;
    };
};


class LevelDirector {
public:
    virtual void construct(LevelBuilder *builder) {};
};

class BossLevel : public LevelDirector {
public:
    void construct(LevelBuilder *builder) override {
        cout << "Creating Boss Level:" << endl;
        builder->createPlatform(Position(1, 1), 100);
        builder->createCharacter(Position(20, 1));
        cout << "Creating Boss:" << endl;
        builder->createEnemy(Position(40, 1));
    }
};


//int main() {
//    //    for(int i=0;i<10;i++)
////        marioLevel->createPlatform(new Position(d[i].x,d[i].y),d[i].l);
////    marioLevel->createCharacter(new Position(d[0].x,d[0].y));
////    Random r=new Random();
////    for(int i=0;i<100;i++)
////        builder.createEnemy(new Position(r.nextInt(100), r.nextInt(100)));
////    Level level = builder.getLevel();
//    LevelBuilder *marioLevel = new MarioLevelBuilder();
//    marioLevel->print();
//    LevelDirector *bossLevel = new BossLevel();
//    bossLevel->construct(marioLevel);
//    return 0;
//}

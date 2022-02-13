#include "Builder.cpp"
#include <iostream>

using namespace std;



int main() {
    //    for(int i=0;i<10;i++)
//        marioLevel->createPlatform(new Position(d[i].x,d[i].y),d[i].l);
//    marioLevel->createCharacter(new Position(d[0].x,d[0].y));
//    Random r=new Random();
//    for(int i=0;i<100;i++)
//        builder.createEnemy(new Position(r.nextInt(100), r.nextInt(100)));
//    Level level = builder.getLevel();
    LevelBuilder* marioLevel = new MarioLevelBuilder();
    marioLevel->print();
    LevelDirector *bossLevel = new BossLevel();
    bossLevel->construct(marioLevel);
    // Level *l = marioLevel->getLevel();

    return 0;
}

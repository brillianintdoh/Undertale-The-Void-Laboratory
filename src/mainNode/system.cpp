#include "mainNode.h"
using namespace godot;

vector<function<void()>> sleepFuns;
vector<double> sleepCool, sleepTime;
void MainNode::sleep(function<void()> fun, double cool) {
    sleepFuns.push_back(fun);
    sleepCool.push_back(cool);
    sleepTime.push_back(0);
}

vector<function<int(double delta)>> loopFuns;
int isLoop = false;
void MainNode::loop(function<int(double delta)> fun) {
    loopFuns.push_back(fun);
    isLoop = true;
}

void MainNode::system(double delta) {
    int i1 = 0;
    for(auto fun : sleepFuns) {
        if(sleepCool[i1] <= sleepTime[i1]) {
            fun();
            sleepCool.erase(sleepCool.begin() + i1);
            sleepTime.erase(sleepTime.begin() + i1);
            sleepFuns.erase(sleepFuns.begin() + i1);
        }else {
            sleepTime[i1]+=delta;
            i1++;
        }
    }

    int i2 = 0;
    for(auto fun : loopFuns) {
        if(fun(delta)) 
            loopFuns.erase(loopFuns.begin() + i2);
        else i2++;
    }
}
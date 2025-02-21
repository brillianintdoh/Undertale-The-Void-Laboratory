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

void MainNode::sequence(function<int()> isFun, vector<function<void()>> funs) {
    loop([this, funs, isFun](double delta) {
        static size_t current_index = 0;
        
        if (isFun()) {
            if (current_index < funs.size()) {
                funs[current_index]();
                current_index++;
                return false;
            }
            current_index = 0;  // 리셋
            return true;  // 모든 액션 완료
        }else return false;
    });
}

void MainNode::time_loop(function<void(double delta)> fun, double time) {
    double* total_time = new double(0);
    
    loop([fun, time, total_time](double delta) {
        *total_time += delta;
        
        if(*total_time >= time) {
            delete total_time;
            return true;
        }

        fun(delta);
        return false;
    });
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
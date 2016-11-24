//
// Created by Lawrence Lee on 24/11/2016.
//

#include "ParkingLot.h"

ParkingLot::ParkingLot(const string &name, const int maxSpace) : name(name), maxSpace(maxSpace) {}

void ParkingLot::run() {
    int selection;
    do {

        cout << "请选择要执行的操作" << endl;
        cout << "1. 停车" << endl;
        cout << "2. 取车" << endl;
        cout << "3. 查看车辆状态" << endl;
        cout << "0. 退出停车系统" << endl;
        cin >> selection;
        switch (selection) {
            case 1:
                parkVehicle();
                break;
            case 2:
                fetchVehicle();
                break;
            case 3:
                checkVehicleStatus();
                break;
            case 0:
                break;
            default:
                cout << "指令错误！" << endl;
        }
    } while (selection);
}

void ParkingLot::parkVehicle() {
    char selection;
    int selectionN;
    string vehicleID;
    int vehicleType;
    time_t enterTime = time(nullptr);
    cout << "请输入您的车牌号" << endl;
    cin >> vehicleID;
    cout << "请输入您的车辆类型（1. 小型车 | 2. 大型车）" << endl;
    cin >> vehicleType;
    cout << "请核查您输入的信息：" << endl;
    cout << "车牌号：" << vehicleID << endl;
    cout << "车辆类型：" << vehicleType << endl;
    cout << "上述信息是否正确？(Y/N)" << endl;
    cin >> selection;
    if(selection == 'Y' || selection == 'y') {
        Vehicle vehicle = Vehicle(vehicleID, enterTime, vehicleType);
        if(parkingSpace.size() < maxSpace) {
            cout << "已成功停车！" << "您是第 " << parkingSpace.size() + 1 << "个停入的车辆！";
            cout << "停车时间：" << asctime(localtime(&enterTime)) << endl;
            parkingSpace.push(vehicle);
        } else {
            cout << "停车场已满！" << "您是第 " << waitingLine.size() + 1 << "个等待的车辆！";
            cout << "等待请按 1，离开请按 2" << endl;
            cin >> selectionN;
            if(selectionN == 1) {
                waitingLine.push(vehicle);
                cout << "成功进入等待队列！系统将按顺序自动引导您的车辆进入停车场！" << endl;
            }
        }
    }
}

int ParkingLot::searchVehicle(const string & vehicleID) {
    while(parkingSpace.size()) {
        Vehicle vehicle = parkingSpace.top();
//        cerr << vehicle.getVehicleName() <<  endl;

        if(vehicle.getVehicleName() == vehicleID) {
            currentVehicle = vehicle;
//            cerr << currentVehicle.getTimeStamp() << endl;
            while(tempStack.size()) {
                Vehicle tmpVehicle = tempStack.top();
                tempStack.pop();
                parkingSpace.push(tmpVehicle);
            }
            return 1;
        }
        tempStack.push(vehicle);
        parkingSpace.pop();
    }
    while(tempStack.size()) {
        Vehicle tmpVehicle = tempStack.top();
        tempStack.pop();
        parkingSpace.push(tmpVehicle);
    }
    while(waitingLine.size()) {
        Vehicle vehicle = waitingLine.front();
        if(vehicle.getVehicleName() == vehicleID) {
            while(tempQueue.size()) {
                Vehicle tmpVehicle = tempQueue.front();
                tempQueue.pop();
                waitingLine.push(tmpVehicle);
            }
            return 2;
        }
        tempQueue.push(vehicle);
        waitingLine.pop();
    }
    while(tempQueue.size()) {
        Vehicle tmpVehicle = tempQueue.front();
        tempQueue.pop();
        waitingLine.push(tmpVehicle);
    }
    return 3;
}

void ParkingLot::fetchVehicle() {
    string vehicleID;
    char selection;
    time_t enterTime;
    cout << "请输入您的车牌号" << endl;
    cin >> vehicleID;
    if(searchVehicle(vehicleID) == 1) {
        cout << "您的车辆信息：" << endl;
        cout << "车牌号：" << currentVehicle.getVehicleName() << endl;
        cout << "车辆类型：" << currentVehicle.getVehicleType() << endl;
        enterTime = currentVehicle.getTimeStamp();
        cout << "入场时间：" << asctime(localtime(&enterTime)) << endl;
        cout << "消费：" << currentVehicle.countFee() << "元" << endl;
        cout << "确认取车吗？" << endl;
        cin >> selection;
        if(selection == 'Y' || selection == 'y') {
            countFee(vehicleID);
            cout << "欢迎下次光临！" << endl;
        }
    } else {
        cout << "您的车辆不在停车场内！" << endl;
    }

}

void ParkingLot::countFee(string & vehicleID) {
    while(parkingSpace.size()) {
        Vehicle vehicle = parkingSpace.top();
        if(vehicle.getVehicleName() == vehicleID) {
            parkingSpace.pop();
        } else {
            parkingSpace.pop();
            tempStack.push(vehicle);
        }
    }
    while(tempStack.size()) {
        Vehicle vehicle = tempStack.top();
        tempStack.pop();
        parkingSpace.push(vehicle);
    }
    if(waitingLine.size()) {
        Vehicle readyV = waitingLine.front();
        readyV.setTimeStamp(time(nullptr));
        waitingLine.pop();
        parkingSpace.push(readyV);
    }
}

void ParkingLot::checkVehicleStatus() {
    string vehicleID;
    time_t enterTime;
    cout << "请输入您的车牌号" << endl;
    cin >> vehicleID;
    switch(searchVehicle(vehicleID)) {
        case 1:
            cout << "您的车辆在停车场中！" << endl;
            break;
        case 2:
            cout << "您的车辆还在等待！" << endl;
            break;
        default:
            cout << "未找到车辆信息！" << endl;
    }
}
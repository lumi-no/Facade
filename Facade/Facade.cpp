#include <iostream>
#include <string>

class Subsystem1 {
public:
    std::string Operation1() const {
        return "Subsystem1: ������ ������\n";
    }
    std::string OperationN() const {
        return "Subsystem1: ���������� ������\n";
    }
};

class Subsystem2 {
public:
    std::string Operation1() const {
        return "Subsystem2: ������� ��������\n";
    }
    std::string OperationZ() const {
        return "Subsystem2: ���������� ��������\n";
    }
};

class Facade {
private:
    Subsystem1* subsystem1_;
    Subsystem2* subsystem2_;

public:
    Facade(Subsystem1* subsystem1, Subsystem2* subsystem2)
        : subsystem1_(subsystem1), subsystem2_(subsystem2) {}

    std::string Operation() const {
        std::string result = "Facade: ������ ������ ��������:\n";
        result += subsystem1_->Operation1();
        result += subsystem2_->Operation1();
        result += subsystem1_->OperationN();
        result += subsystem2_->OperationZ();
        return result;
    }
};

void ClientCode(const Facade& facade) {
    std::cout << facade.Operation();
}

int main() {
    Subsystem1* subsystem1 = new Subsystem1;
    Subsystem2* subsystem2 = new Subsystem2;

    Facade* facade = new Facade(subsystem1, subsystem2);
    std::cout << "�볺��: ������������ ����� ��� ��������� ������:\n";
    ClientCode(*facade);

    
    delete facade;
    delete subsystem1;
    delete subsystem2;

    return 0;
}

#pragma once
#include "enums.h"
#include <ctime>
#include <memory>
#include <string>

class Person {
protected:
    int id;
    std::string full_name;

public:
    Person(int id, const std::string& name) : id(id), full_name(name) {}
    virtual ~Person() = default;

    int getId() const { return id; }
    const std::string& getFullName() const { return full_name; }

    virtual void printInfo() const {
        std::cout << "ID: " << id << ", ПІБ: " << full_name;
    }
};

class MedicalInstitution {
    int id;
    std::string name;
    InstitutionType type;
    std::string address;
    std::string phone;
    std::string head_doctor;

public:
    MedicalInstitution(int id, const std::string& name, InstitutionType type,
        const std::string& address, const std::string& phone,
        const std::string& head_doctor)
        : id(id), name(name), type(type), address(address), phone(phone),
        head_doctor(head_doctor) {
    }

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    InstitutionType getType() const { return type; }
    const std::string& getAddress() const { return address; }
    const std::string& getPhone() const { return phone; }
    const std::string& getHeadDoctor() const { return head_doctor; }
};

class Doctor : public Person {
    std::string specialty;
    int experience_years;
    int operations_count;
    std::string academic_degree;
    int institution_id;

public:
    Doctor(int id, const std::string& full_name, const std::string& specialty,
        int experience_years, int operations_count,
        const std::string& academic_degree, int institution_id)
        : Person(id, full_name), specialty(specialty),
        experience_years(experience_years), operations_count(operations_count),
        academic_degree(academic_degree), institution_id(institution_id) {
    }

    const std::string& getSpecialty() const { return specialty; }
    int getExperienceYears() const { return experience_years; }
    int getOperationsCount() const { return operations_count; }
    const std::string& getAcademicDegree() const { return academic_degree; }
    int getInstitutionId() const { return institution_id; }

    void printInfo() const override {
        Person::printInfo();
        std::cout << ", Спеціальність: " << specialty
            << ", Стаж: " << experience_years << " років";
    }
};

class SupportStaff : public Person {
    std::string role;
    int institution_id;

public:
    SupportStaff(int id, const std::string& full_name, const std::string& role,
        int institution_id)
        : Person(id, full_name), role(role), institution_id(institution_id) {
    }

    // Getters
    const std::string& getRole() const { return role; }
    int getInstitutionId() const { return institution_id; }

    void printInfo() const override {
        Person::printInfo();
        std::cout << ", Посада: " << role;
    }
};

class Patient : public Person {
    std::tm admission_date;
    std::string condition;
    double temperature;
    int doctor_id;
    int ward_id;
    std::string department;
    std::string treatment_history;

public:
    Patient(int id, const std::string& full_name, const std::tm& admission_date,
        const std::string& condition, double temperature, int doctor_id,
        int ward_id, const std::string& department,
        const std::string& treatment_history)
        : Person(id, full_name), admission_date(admission_date),
        condition(condition), temperature(temperature), doctor_id(doctor_id),
        ward_id(ward_id), department(department),
        treatment_history(treatment_history) {
    }

    const std::tm& getAdmissionDate() const { return admission_date; }
    const std::string& getCondition() const { return condition; }
    double getTemperature() const { return temperature; }
    int getDoctorId() const { return doctor_id; }
    int getWardId() const { return ward_id; }
    const std::string& getDepartment() const { return department; }
    const std::string& getTreatmentHistory() const { return treatment_history; }

    void printInfo() const override {
        Person::printInfo();
        std::cout << ", Стан: " << condition << ", Температура: " << temperature;
    }
};

class Ward {
    int id;
    std::string ward_number;
    std::string department;
    int bed_count;
    int available_beds;
    int institution_id;

public:
    Ward(int id, const std::string& ward_number, const std::string& department,
        int bed_count, int available_beds, int institution_id)
        : id(id), ward_number(ward_number), department(department),
        bed_count(bed_count), available_beds(available_beds),
        institution_id(institution_id) {
    }

    // Getters
    int getId() const { return id; }
    const std::string& getWardNumber() const { return ward_number; }
    const std::string& getDepartment() const { return department; }
    int getBedCount() const { return bed_count; }
    int getAvailableBeds() const { return available_beds; }
    int getInstitutionId() const { return institution_id; }
};

class Bed {
    int id;
    std::string bed_number;
    int ward_id;
    BedStatus status;
    int patient_id;

public:
    Bed(int id, const std::string& bed_number, int ward_id, BedStatus status,
        int patient_id = 0)
        : id(id), bed_number(bed_number), ward_id(ward_id), status(status),
        patient_id(patient_id) {
    }

    // Getters
    int getId() const { return id; }
    const std::string& getBedNumber() const { return bed_number; }
    int getWardId() const { return ward_id; }
    BedStatus getStatus() const { return status; }
    int getPatientId() const { return patient_id; }

    void setStatus(BedStatus new_status) { status = new_status; }
    void setPatientId(int pid) { patient_id = pid; }
};

class Room {
    int id;
    std::string room_number;
    int institution_id;
    std::string profile;
    int capacity;

public:
    Room(int id, const std::string& room_number, const std::string& profile,
        int capacity, int institution_id)
        : id(id), room_number(room_number), institution_id(institution_id),
        profile(profile), capacity(capacity) {
    }

    int getId() const { return id; }
    const std::string& getRoomNumber() const { return room_number; }
    int getInstitutionId() const { return institution_id; }
    const std::string& getProfile() const { return profile; }
    int getCapacity() const { return capacity; }
};

class RoomVisit {
    int id;
    std::tm visit_date;
    std::tm visit_time;
    int patient_id;
    int room_id;

public:
    RoomVisit(int id, const std::tm& visit_date, const std::tm& visit_time,
        int patient_id, int room_id)
        : id(id), visit_date(visit_date), visit_time(visit_time),
        patient_id(patient_id), room_id(room_id) {
    }

    int getId() const { return id; }
    const std::tm& getVisitDate() const { return visit_date; }
    const std::tm& getVisitTime() const { return visit_time; }
    int getPatientId() const { return patient_id; }
    int getRoomId() const { return room_id; }
};

class Operation {
    int id;
    std::tm operation_date;
    int patient_id;
    int doctor_id;
    int institution_id;
    std::string description;

public:
    Operation(int id, const std::tm& operation_date, int patient_id,
        int doctor_id, int institution_id, const std::string& description)
        : id(id), operation_date(operation_date), patient_id(patient_id),
        doctor_id(doctor_id), institution_id(institution_id),
        description(description) {
    }

    int getId() const { return id; }
    const std::tm& getOperationDate() const { return operation_date; }
    int getPatientId() const { return patient_id; }
    int getDoctorId() const { return doctor_id; }
    int getInstitutionId() const { return institution_id; }
    const std::string& getDescription() const { return description; }
};

class LabTest {
    int id;
    std::tm test_date;
    std::string test_type;
    int patient_id;
    int institution_id;
    std::string result;

public:
    LabTest(int id, const std::tm& test_date, const std::string& test_type,
        int patient_id, int institution_id, const std::string& result)
        : id(id), test_date(test_date), test_type(test_type),
        patient_id(patient_id), institution_id(institution_id), result(result) {
    }

    int getId() const { return id; }
    const std::tm& getTestDate() const { return test_date; }
    const std::string& getTestType() const { return test_type; }
    int getPatientId() const { return patient_id; }
    int getInstitutionId() const { return institution_id; }
    const std::string& getResult() const { return result; }
};
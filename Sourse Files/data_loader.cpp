#include "data_loader.h"
#include "helpers.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <sstream>

std::vector<std::shared_ptr<MedicalInstitution>>
loadMedicalInstitutionsFromTXT() {
    std::vector<std::shared_ptr<MedicalInstitution>> institutions;
    std::ifstream file("medical_institutions.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл medical_institutions.txt\n";
        return institutions;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 6) {
            std::cerr
                << "Помилка в рядку " << line_num
                << " файлу medical_institutions.txt: Очікувалось 6 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            institutions.push_back(std::make_shared<MedicalInstitution>(
                safe_stoi(data[0], "ID медичного закладу"), data[1],
                parseInstitutionType(data[2]), data[3], data[4], data[5]));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу medical_institutions.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return institutions;
}

std::vector<std::shared_ptr<Doctor>> loadDoctorsFromTXT() {
    std::vector<std::shared_ptr<Doctor>> doctors;
    std::ifstream file("doctors.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл doctors.txt\n";
        return doctors;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 7) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу doctors.txt: Очікувалось 7 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            doctors.push_back(std::make_shared<Doctor>(
                safe_stoi(data[0], "ID лікаря"), data[1], data[2],
                safe_stoi(data[3], "роки досвіду"),
                safe_stoi(data[4], "кількість операцій"), data[5],
                safe_stoi(data[6], "ID закладу лікаря")));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу doctors.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return doctors;
}

std::vector<std::shared_ptr<SupportStaff>> loadSupportStaffFromTXT() {
    std::vector<std::shared_ptr<SupportStaff>> staff;
    std::ifstream file("support_staff.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл support_staff.txt\n";
        return staff;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 4) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу support_staff.txt: Очікувалось 4 поля, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            staff.push_back(std::make_shared<SupportStaff>(
                safe_stoi(data[0], "ID молодшого медперсоналу"), data[1], data[2],
                safe_stoi(data[3], "ID закладу молодшого медперсоналу")));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу support_staff.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return staff;
}

std::vector<std::shared_ptr<Patient>> loadPatientsFromTXT() {
    std::vector<std::shared_ptr<Patient>> patients;
    std::ifstream file("patients.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл patients.txt\n";
        return patients;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 7 && data.size() != 9) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу patients.txt: Очікувалось 7 або 9 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            patients.push_back(std::make_shared<Patient>(
                safe_stoi(data[0], "ID пацієнта"), data[1], parseDate(data[2]),
                data[3], safe_stod(data[4], "температура"),
                safe_stoi(data[5], "ID лікаря"), safe_stoi(data[6], "ID палати"),
                data.size() == 9 ? data[7] : "", data.size() == 9 ? data[8] : ""));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу patients.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return patients;
}

std::vector<std::shared_ptr<Ward>> loadWardsFromTXT() {
    std::vector<std::shared_ptr<Ward>> wards;
    std::ifstream file("wards.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл wards.txt\n";
        return wards;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 6) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу wards.txt: Очікувалось 6 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            wards.push_back(
                std::make_shared<Ward>(safe_stoi(data[0], "ID палати"), data[1],
                    data[2], safe_stoi(data[3], "кількість ліжок"),
                    safe_stoi(data[4], "доступні ліжка"),
                    safe_stoi(data[5], "ID закладу палати")));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу wards.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return wards;
}

std::vector<std::shared_ptr<Bed>> loadBedsFromTXT() {
    std::vector<std::shared_ptr<Bed>> beds;
    std::ifstream file("beds.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити beds.txt\n";
        return beds;
    }

    std::string line;
    std::getline(file, line); // Skip header

    if (!validateHeader(line, { "id", "ward_id", "status", "patient_id" })) {
        std::cerr << "Помилка: Невірний формат заголовку у beds.txt\n";
        return {};
    }

    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            fields.push_back(field);
        }

        if (fields.size() < 4) {
            std::cerr << "Попередження: Рядок " << line_num
                << " файлу beds.txt має лише " << fields.size()
                << " полів (потрібно мінімум 4)\n";
            continue;
        }

        try {
            beds.push_back(std::make_shared<Bed>(
                safe_stoi(fields[0], "ID ліжка"), fields.size() > 1 ? fields[1] : "",
                safe_stoi(fields[1], "ID палати"), parseBedStatus(fields[2]),
                fields.size() > 3 ? safe_stoi(fields[3], "ID пацієнта") : 0));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу beds.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return beds;
}

std::vector<std::shared_ptr<Room>> loadRoomsFromTXT() {
    std::vector<std::shared_ptr<Room>> rooms;
    std::ifstream file("rooms.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити rooms.txt\n";
        return rooms;
    }

    std::string line;
    std::getline(file, line); // Skip header

    if (!validateHeader(line, { "id", "room_number", "profile", "capacity",
                               "institution_id" })) {
        std::cerr << "Помилка: Невірний формат заголовку у rooms.txt\n";
        return {};
    }

    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            fields.push_back(field);
        }

        if (fields.size() < 4) {
            std::cerr << "Попередження: Рядок " << line_num
                << " файлу rooms.txt має лише " << fields.size()
                << " полів (потрібно мінімум 4)\n";
            continue;
        }

        try {
            rooms.push_back(std::make_shared<Room>(
                safe_stoi(fields[0], "ID кабінету"), fields[1], fields[2],
                fields.size() > 3 ? safe_stoi(fields[3], "Місткість кабінету") : 0,
                fields.size() > 4 ? safe_stoi(fields[4], "ID закладу") : 0));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу rooms.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return rooms;
}

std::vector<std::shared_ptr<RoomVisit>> loadRoomVisitsFromTXT() {
    std::vector<std::shared_ptr<RoomVisit>> visits;
    std::ifstream file("room_visits.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл room_visits.txt\n";
        return visits;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 5) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу room_visits.txt: Очікувалось 5 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            visits.push_back(std::make_shared<RoomVisit>(
                safe_stoi(data[0], "ID відвідування"), parseDate(data[1]),
                parseTime(data[2]), safe_stoi(data[3], "ID пацієнта"),
                safe_stoi(data[4], "ID кабінету")));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу room_visits.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return visits;
}

std::vector<std::shared_ptr<Operation>> loadOperationsFromTXT() {
    std::vector<std::shared_ptr<Operation>> operations;
    std::ifstream file("operations.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл operations.txt\n";
        return operations;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 6) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу operations.txt: Очікувалось 6 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            operations.push_back(std::make_shared<Operation>(
                safe_stoi(data[0], "ID операції"), parseDate(data[1]),
                safe_stoi(data[2], "ID пацієнта"), safe_stoi(data[3], "ID лікаря"),
                safe_stoi(data[4], "ID кабінету"), data[5]));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу operations.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return operations;
}

std::vector<std::shared_ptr<LabTest>> loadLabTestsFromTXT() {
    std::vector<std::shared_ptr<LabTest>> labTests;
    std::ifstream file("lab_tests.txt");

    if (!file.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл lab_tests.txt\n";
        return labTests;
    }

    std::string line;
    std::getline(file, line); // Skip header
    int line_num = 1;

    while (std::getline(file, line)) {
        line_num++;
        std::stringstream ss(line);
        std::vector<std::string> data;
        std::string field;

        while (std::getline(ss, field, '\t')) {
            data.push_back(field);
        }

        if (data.size() != 6) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу lab_tests.txt: Очікувалось 6 полів, отримано "
                << data.size() << "\n";
            continue;
        }

        try {
            labTests.push_back(std::make_shared<LabTest>(
                safe_stoi(data[0], "ID аналізу"), parseDate(data[1]), data[2],
                safe_stoi(data[3], "ID пацієнта"), safe_stoi(data[4], "ID закладу"),
                data[5]));
        }
        catch (const std::exception& e) {
            std::cerr << "Помилка в рядку " << line_num
                << " файлу lab_tests.txt: " << e.what() << "\n";
        }
    }
    file.close();
    return labTests;
}
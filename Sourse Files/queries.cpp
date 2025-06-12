#include "queries.h"
#include "helpers.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>

void query1_getDoctorsBySpecialtyAndInstitution(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::string& specialty, int institutionId) {

    std::cout << "\n*** Запит 1: Лікарі профілю '" << specialty << "'";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    std::vector<std::shared_ptr<Doctor>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& doctor : doctors) {
        if (doctor->getSpecialty() == specialty) {
            if (institutionId == 0 || doctor->getInstitutionId() == institutionId) {
                result.push_back(doctor);
                doctor->printInfo(); // поліморфізм
                std::cout << std::endl;
            }
        }
    }

    std::cout << "Загальна кількість лікарів профілю '" << specialty << "' ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << result.size() << std::endl;
}

void query2_getSupportStaffByRoleAndInstitution(
    const std::vector<std::shared_ptr<SupportStaff>>& supportStaff,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::string& role, int institutionId) {

    std::cout << "\n*** Запит 2: Обслуговуючий персонал за посадою '" << role
        << "'";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    std::vector<std::shared_ptr<SupportStaff>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& staff : supportStaff) {
        if (staff->getRole() == role) {
            if (institutionId == 0 || staff->getInstitutionId() == institutionId) {
                result.push_back(staff);
                staff->printInfo();
                std::cout << std::endl;
            }
        }
    }

    std::cout << "Загальна кількість обслуговуючого персоналу за посадою '"
        << role << "' ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << result.size() << std::endl;
}

void query3_getDoctorsBySpecialtyAndMinOperations(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::string& specialty, int minOperations, int institutionId) {

    std::cout << "\n*** Запит 3: Лікарі профілю '" << specialty
        << "' з кількістю операцій не менше " << minOperations;
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    std::vector<std::shared_ptr<Doctor>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& doctor : doctors) {
        if (doctor->getSpecialty() == specialty &&
            doctor->getOperationsCount() >= minOperations) {
            if (institutionId == 0 || doctor->getInstitutionId() == institutionId) {
                result.push_back(doctor);
                doctor->printInfo();
                std::cout << ", Кількість операцій: " << doctor->getOperationsCount()
                    << std::endl;
            }
        }
    }

    std::cout << "Загальна кількість лікарів профілю '" << specialty
        << "' з кількістю операцій не менше " << minOperations << " ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << result.size() << std::endl;
}

void query4_getDoctorsBySpecialtyAndMinExperience(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::string& specialty, int minExperienceYears, int institutionId) {

    std::cout << "\n*** Запит 4: Лікарі профілю '" << specialty
        << "' зі стажем роботи не менше " << minExperienceYears << " років";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    std::vector<std::shared_ptr<Doctor>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& doctor : doctors) {
        if (doctor->getSpecialty() == specialty &&
            doctor->getExperienceYears() >= minExperienceYears) {
            if (institutionId == 0 || doctor->getInstitutionId() == institutionId) {
                result.push_back(doctor);
                doctor->printInfo();
                std::cout << ", Стаж роботи: " << doctor->getExperienceYears()
                    << " років" << std::endl;
            }
        }
    }

    std::cout << "Загальна кількість лікарів профілю '" << specialty
        << "' зі стажем роботи не менше " << minExperienceYears
        << " років ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << result.size() << std::endl;
}

void query5_getDoctorsBySpecialtyAndAcademicTitle(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::string& specialty, int institutionId) {

    std::cout << "\n*** Запит 5: Лікарі профілю '" << specialty
        << "' з науковим ступенем/званням";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    std::vector<std::shared_ptr<Doctor>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& doctor : doctors) {
        if (doctor->getSpecialty() == specialty &&
            hasAcademicTitle(doctor->getAcademicDegree())) {
            if (institutionId == 0 || doctor->getInstitutionId() == institutionId) {
                result.push_back(doctor);
                doctor->printInfo();
                std::cout << ", Науковий ступінь/звання: "
                    << doctor->getAcademicDegree() << std::endl;
            }
        }
    }

    std::cout << "Загальна кількість лікарів профілю '" << specialty
        << "' з науковим ступенем/званням: ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << result.size() << std::endl;
}

void query6_getPatientsByLocation(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Ward>>& wards, int institutionId,
    const std::string& department, int wardId) {
    std::cout << "\n*** Запит 6: Перелік пацієнтів ";
    if (institutionId != 0) {
        std::cout << "у медичному закладі з ID " << institutionId;
        if (!department.empty()) {
            std::cout << ", відділення '" << department << "'";
            if (wardId != 0) {
                std::cout << ", палата з ID " << wardId;
            }
        }
        std::cout << " ***\n";
    }
    else {
        std::cout << "у всіх медичних закладах (фільтрація за відділенням/палатою "
            "неможлива) ***\n";
    }

    std::vector<std::shared_ptr<Patient>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& patient : patients) {
        bool institutionMatch = (institutionId == 0);
        bool departmentMatch = department.empty();
        bool wardMatch = (wardId == 0);

        for (const auto& ward : wards) {
            if (patient->getWardId() == ward->getId()) {
                if (institutionId != 0 && ward->getInstitutionId() == institutionId) {
                    institutionMatch = true;
                }
                else if (institutionId == 0) {
                    institutionMatch = true;
                }

                if (!department.empty() && ward->getDepartment() == department) {
                    departmentMatch = true;
                }

                if (wardId != 0 && patient->getWardId() == wardId) {
                    wardMatch = true;
                }
                break;
            }
        }

        if (institutionMatch && departmentMatch && wardMatch) {
            result.push_back(patient);
            patient->printInfo();
            std::cout << ", Дата надходження: "
                << std::put_time(&patient->getAdmissionDate(), "%d.%m.%Y")
                << ", Стан: " << patient->getCondition()
                << ", Температура: " << std::fixed << std::setprecision(2)
                << patient->getTemperature() << ", Лікуючий лікар: "
                << getDoctorFullName(patient->getDoctorId(), doctors)
                << std::endl;
        }
    }

    std::cout << "Загальна кількість пацієнтів за заданими критеріями: "
        << result.size() << std::endl;
}

void query7_getPatientsByTreatmentPeriod(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Ward>>& wards, int institutionId,
    int wardId, int doctorId, const std::tm& startDate,
    const std::tm& endDate) {
    std::cout << "\n*** Запит 7: Пацієнти, які пройшли стаціонарне лікування";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId;
    }
    if (doctorId != 0) {
        std::cout << " у лікаря з ID " << doctorId << " ("
            << getDoctorFullName(doctorId, doctors) << ")";
    }
    if (mktime(const_cast<std::tm*>(&startDate))) {
        std::cout << " за період з " << std::put_time(&startDate, "%d.%m.%Y")
            << " по " << std::put_time(&endDate, "%d.%m.%Y");
    }
    std::cout << " ***\n";

    std::vector<std::shared_ptr<Patient>> result;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& patient : patients) {
        bool institutionMatch = (institutionId == 0);
        bool doctorMatch = (doctorId == 0 || patient->getDoctorId() == doctorId);
        bool dateMatch =
            (!mktime(const_cast<std::tm*>(&startDate))) ||
            isDateInRange(patient->getAdmissionDate(), startDate, endDate);
        bool wardFilterMatch = (wardId == 0);

        for (const auto& ward : wards) {
            if (patient->getWardId() == ward->getId()) {
                if (institutionId != 0 && ward->getInstitutionId() == institutionId) {
                    institutionMatch = true;
                }
                else if (institutionId == 0) {
                    institutionMatch = true;
                }

                if (wardId != 0 && patient->getWardId() == wardId) {
                    wardFilterMatch = true;
                }
                break;
            }
        }

        if (institutionMatch && doctorMatch && dateMatch &&
            patient->getWardId() != 0 && wardFilterMatch) {
            result.push_back(patient);
            patient->printInfo();
            std::cout << ", Дата надходження: "
                << std::put_time(&patient->getAdmissionDate(), "%d.%m.%Y")
                << ", Лікуючий лікар: "
                << getDoctorFullName(patient->getDoctorId(), doctors)
                << std::endl;
        }
    }

    std::cout << "Загальна кількість пацієнтів за заданими критеріями: "
        << result.size() << std::endl;
}

void query8_getPatientsByDoctorSpecialtyAndPolyclinic(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::string& doctorSpecialty, int polyclinicId) {

    std::cout << "\n*** Запит 8: Пацієнти, що спостерігаються у лікаря профілю '"
        << doctorSpecialty << "' в поліклініці з ID " << polyclinicId
        << " ***\n";

    std::vector<std::shared_ptr<Patient>> result;
    std::string polyclinicName = "не знайдено";

    for (const auto& inst : medicalInstitutions) {
        if (inst->getId() == polyclinicId &&
            inst->getType() == InstitutionType::polyclinic) {
            polyclinicName = inst->getName();
            std::cout << "Поліклініка: " << polyclinicName << "\n";
            break;
        }
        else if (inst->getId() == polyclinicId &&
            inst->getType() != InstitutionType::polyclinic) {
            std::cout << "Помилка: Заклад з ID " << polyclinicId
                << " не є поліклінікою.\n";
            return;
        }
    }

    if (polyclinicName == "не знайдено") {
        std::cout << "Помилка: Поліклініку з ID " << polyclinicId
            << " не знайдено.\n";
        return;
    }

    for (const auto& patient : patients) {
        for (const auto& doctor : doctors) {
            if (patient->getDoctorId() == doctor->getId() &&
                doctor->getSpecialty() == doctorSpecialty &&
                doctor->getInstitutionId() == polyclinicId) {

                result.push_back(patient);
                patient->printInfo();
                std::cout << ", Лікуючий лікар (ID " << doctor->getId()
                    << "): " << doctor->getFullName()
                    << ", Спеціальність лікаря: " << doctor->getSpecialty()
                    << std::endl;
                break;
            }
        }
    }

    std::cout
        << "Загальна кількість пацієнтів, що спостерігаються у лікарів профілю '"
        << doctorSpecialty << "' в поліклініці '" << polyclinicName
        << "': " << result.size() << std::endl;
}

void query9_getTotalBedsByInstitutionAndStatus(
    const std::vector<std::shared_ptr<Ward>>& wards,
    const std::vector<std::shared_ptr<Bed>>& beds,
    const std::vector<std::shared_ptr<MedicalInstitution>>& medicalInstitutions,
    int institutionId, BedStatus status) {

    std::cout << "\n*** Запит 9: Загальна кількість ліжок зі статусом '" << status
        << "'";
    if (institutionId != 0) {
        std::cout << " у медичному закладі з ID " << institutionId << " ***\n";
    }
    else {
        std::cout << " у всіх медичних закладах ***\n";
    }

    int totalBeds = 0;
    std::string institutionName = "усі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : medicalInstitutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
        std::cout << "Медичний заклад: " << institutionName << "\n";
    }

    for (const auto& ward : wards) {
        if (institutionId == 0 || ward->getInstitutionId() == institutionId) {
            for (const auto& bed : beds) {
                if (bed->getWardId() == ward->getId() && bed->getStatus() == status) {
                    totalBeds++;
                }
            }
        }
    }

    std::cout << "Загальна кількість ліжок зі статусом '" << status << "' ";
    if (institutionId != 0) {
        std::cout << "у закладі '" << institutionName << "': ";
    }
    else {
        std::cout << "у всіх закладах: ";
    }
    std::cout << totalBeds << std::endl;
}

void query10_getRoomsAndVisitsByPolyclinic(
    const std::vector<std::shared_ptr<Room>>& rooms,
    const std::vector<std::shared_ptr<RoomVisit>>& roomVisits,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int polyclinicId, const std::tm& startDate, const std::tm& endDate) {

    std::cout << "\n*** Запит 10: Кабінети поліклініки з ID " << polyclinicId
        << " та кількість відвідувань за період "
        << std::put_time(&startDate, "%d.%m.%Y") << " - "
        << std::put_time(&endDate, "%d.%m.%Y") << " ***\n";

    // Перевірка, чи це поліклініка
    std::string polyclinicName = "не знайдено";
    for (const auto& inst : institutions) {
        if (inst->getId() == polyclinicId &&
            inst->getType() == InstitutionType::polyclinic) {
            polyclinicName = inst->getName();
            break;
        }
    }

    if (polyclinicName == "не знайдено") {
        std::cout << "Помилка: Заклад з ID " << polyclinicId
            << " не є поліклінікою або не існує\n";
        return;
    }

    std::cout << "Поліклініка: " << polyclinicName << "\n";

    // Збираємо кабінети цієї поліклініки
    std::vector<std::shared_ptr<Room>> polyclinicRooms;
    for (const auto& room : rooms) {
        if (room->getInstitutionId() == polyclinicId) {
            polyclinicRooms.push_back(room);
        }
    }

    std::cout << "Загальна кількість кабінетів у поліклініці: "
        << polyclinicRooms.size() << "\n";

    // Рахуємо відвідування для кожного кабінету
    for (const auto& room : polyclinicRooms) {
        int visitCount = 0;
        for (const auto& visit : roomVisits) {
            if (visit->getRoomId() == room->getId() &&
                isDateInRange(visit->getVisitDate(), startDate, endDate)) {
                visitCount++;
            }
        }
        std::cout << "- Кабінет " << room->getRoomNumber() << " ("
            << room->getProfile() << "): " << visitCount << " відвідувань\n";
    }
}

void query11_getDoctorProductivity(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<RoomVisit>>& roomVisits,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int doctorId, int polyclinicId, const std::string& specialty,
    const std::tm& startDate, const std::tm& endDate) {

    std::cout << "\n*** Запит 11: Продуктивність лікарів за період "
        << std::put_time(&startDate, "%d.%m.%Y") << " - "
        << std::put_time(&endDate, "%d.%m.%Y") << " ***\n";

    // Визначаємо, яких лікарів аналізувати
    std::vector<std::shared_ptr<Doctor>> targetDoctors;

    if (doctorId != 0) {
        // Конкретний лікар
        for (const auto& doctor : doctors) {
            if (doctor->getId() == doctorId) {
                targetDoctors.push_back(doctor);
                break;
            }
        }
    }
    else if (polyclinicId != 0) {
        // Всі лікарі поліклініки
        for (const auto& doctor : doctors) {
            if (doctor->getInstitutionId() == polyclinicId) {
                targetDoctors.push_back(doctor);
            }
        }
    }
    else if (!specialty.empty()) {
        // Всі лікарі певного профілю
        for (const auto& doctor : doctors) {
            if (doctor->getSpecialty() == specialty) {
                targetDoctors.push_back(doctor);
            }
        }
    }
    else {
        std::cout << "Помилка: Не вказано критерії вибору лікарів\n";
        return;
    }

    if (targetDoctors.empty()) {
        std::cout << "Лікарів за вказаними критеріями не знайдено\n";
        return;
    }

    // Рахуємо кількість днів у періоді
    int daysInPeriod = daysBetween(startDate, endDate);
    if (daysInPeriod <= 0) {
        std::cout << "Помилка: Невірний період\n";
        return;
    }

    // Аналізуємо продуктивність кожного лікаря
    for (const auto& doctor : targetDoctors) {
        int patientCount = 0;

        // Рахуємо кількість відвідувань цього лікаря
        for (const auto& visit : roomVisits) {
            if (visit->getPatientId() == doctor->getId() &&
                isDateInRange(visit->getVisitDate(), startDate, endDate)) {
                patientCount++;
            }
        }

        double avgPatientsPerDay = static_cast<double>(patientCount) / daysInPeriod;

        std::cout << "- Лікар: " << doctor->getFullName()
            << " (ID: " << doctor->getId()
            << ", Спеціальність: " << doctor->getSpecialty() << ")\n";
        std::cout << "  Загальна кількість прийомів: " << patientCount << "\n";
        std::cout << "  Середня кількість прийомів за день: " << std::fixed
            << std::setprecision(2) << avgPatientsPerDay << "\n";
    }
}

void query12_getDoctorWorkload(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int doctorId, int hospitalId, const std::string& specialty) {

    std::cout
        << "\n*** Запит 12: Завантаження лікарів (кількість пацієнтів) ***\n";

    // Визначаємо, яких лікарів аналізувати
    std::vector<std::shared_ptr<Doctor>> targetDoctors;

    if (doctorId != 0) {
        // Конкретний лікар
        for (const auto& doctor : doctors) {
            if (doctor->getId() == doctorId) {
                targetDoctors.push_back(doctor);
                break;
            }
        }
    }
    else if (hospitalId != 0) {
        // Всі лікарі лікарні
        for (const auto& doctor : doctors) {
            bool worksInHospital = false;
            for (const auto& inst : institutions) {
                if (inst->getId() == hospitalId &&
                    inst->getType() == InstitutionType::hospital) {
                    worksInHospital = true;
                    break;
                }
            }
            if (worksInHospital) {
                targetDoctors.push_back(doctor);
            }
        }
    }
    else if (!specialty.empty()) {
        // Всі лікарі певного профілю
        for (const auto& doctor : doctors) {
            if (doctor->getSpecialty() == specialty) {
                targetDoctors.push_back(doctor);
            }
        }
    }
    else {
        std::cout << "Помилка: Не вказано критерії вибору лікарів\n";
        return;
    }

    if (targetDoctors.empty()) {
        std::cout << "Лікарів за вказаними критеріями не знайдено\n";
        return;
    }

    // Рахуємо кількість пацієнтів для кожного лікаря
    for (const auto& doctor : targetDoctors) {
        int patientCount = 0;
        for (const auto& patient : patients) {
            if (patient->getDoctorId() == doctor->getId()) {
                patientCount++;
            }
        }

        std::cout << "- Лікар: " << doctor->getFullName()
            << " (ID: " << doctor->getId()
            << ", Спеціальність: " << doctor->getSpecialty() << ")\n";
        std::cout << "  Кількість пацієнтів: " << patientCount << "\n";
    }
}

void query13_getPatientsWithOperations(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<Operation>>& operations,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int hospitalId, int polyclinicId, int doctorId, const std::tm& startDate,
    const std::tm& endDate) {

    std::cout << "\n*** Запит 13: Пацієнти, які перенесли операції за період "
        << std::put_time(&startDate, "%d.%m.%Y") << " - "
        << std::put_time(&endDate, "%d.%m.%Y") << " ***\n";

    // Перевіряємо, що не вказано одночасно лікарню та поліклініку
    if (hospitalId != 0 && polyclinicId != 0) {
        std::cout << "Помилка: Не можна вказати одночасно лікарню та поліклініку\n";
        return;
    }

    // Фільтруємо операції за періодом
    std::vector<std::shared_ptr<Operation>> filteredOperations;
    for (const auto& op : operations) {
        if (isDateInRange(op->getOperationDate(), startDate, endDate)) {
            filteredOperations.push_back(op);
        }
    }

    // Додатково фільтруємо за критеріями
    std::vector<std::shared_ptr<Operation>> targetOperations;
    for (const auto& op : filteredOperations) {
        bool matchesCriteria = true;

        if (doctorId != 0 && op->getDoctorId() != doctorId) {
            matchesCriteria = false;
        }

        if (hospitalId != 0) {
            bool foundInHospital = false;
            for (const auto& inst : institutions) {
                if (inst->getId() == op->getInstitutionId() &&
                    inst->getType() == InstitutionType::hospital) {
                    foundInHospital = true;
                    break;
                }
            }
            if (!foundInHospital)
                matchesCriteria = false;
        }

        if (polyclinicId != 0 && op->getInstitutionId() != polyclinicId) {
            matchesCriteria = false;
        }

        if (matchesCriteria) {
            targetOperations.push_back(op);
        }
    }

    // Виводимо результат
    std::cout << "Загальна кількість операцій за критеріями: "
        << targetOperations.size() << "\n";

    for (const auto& op : targetOperations) {
        // Знаходимо пацієнта
        std::shared_ptr<Patient> patient = nullptr;
        for (const auto& p : patients) {
            if (p->getId() == op->getPatientId()) {
                patient = p;
                break;
            }
        }

        // Знаходимо лікаря
        std::shared_ptr<Doctor> doctor = nullptr;
        for (const auto& d : doctors) {
            if (d->getId() == op->getDoctorId()) {
                doctor = d;
                break;
            }
        }

        // Знаходимо заклад
        std::shared_ptr<MedicalInstitution> institution = nullptr;
        for (const auto& inst : institutions) {
            if (inst->getId() == op->getInstitutionId()) {
                institution = inst;
                break;
            }
        }

        if (patient && doctor && institution) {
            std::cout << "- Пацієнт: " << patient->getFullName()
                << " (ID: " << patient->getId() << ")\n";
            std::cout << "  Лікар: " << doctor->getFullName() << " ("
                << doctor->getSpecialty() << ")\n";
            std::cout << "  Медичний заклад: " << institution->getName() << " ("
                << institution->getType() << ")\n";
            std::cout << "  Дата операції: "
                << std::put_time(&op->getOperationDate(), "%d.%m.%Y") << "\n";
            std::cout << "  Опис: " << op->getDescription() << "\n";
        }
    }
}

void query14_getLabProductivity(
    const std::vector<std::shared_ptr<LabTest>>& labTests,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int institutionId, const std::tm& startDate, const std::tm& endDate) {

    std::cout << "\n*** Запит 14: Продуктивність лабораторії за період "
        << std::put_time(&startDate, "%d.%m.%Y") << " - "
        << std::put_time(&endDate, "%d.%m.%Y") << " ***\n";

    // Рахуємо кількість днів у періоді
    int daysInPeriod = daysBetween(startDate, endDate);
    if (daysInPeriod <= 0) {
        std::cout << "Помилка: Невірний період\n";
        return;
    }

    // Фільтруємо тести за періодом та закладом
    int totalTests = 0;
    std::string institutionName = "всі медичні заклади";

    if (institutionId != 0) {
        for (const auto& inst : institutions) {
            if (inst->getId() == institutionId) {
                institutionName = inst->getName();
                break;
            }
        }
    }

    for (const auto& test : labTests) {
        if (isDateInRange(test->getTestDate(), startDate, endDate) &&
            (institutionId == 0 || test->getInstitutionId() == institutionId)) {
            totalTests++;
        }
    }

    double avgTestsPerDay = static_cast<double>(totalTests) / daysInPeriod;

    std::cout << "Медичний заклад: " << institutionName << "\n";
    std::cout << "Загальна кількість тестів: " << totalTests << "\n";
    std::cout << "Середня кількість тестів за день: " << std::fixed
        << std::setprecision(2) << avgTestsPerDay << "\n";
}
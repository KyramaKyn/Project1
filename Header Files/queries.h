#pragma once
#include "classes.h"
#include <ctime>
#include <memory>
#include <string>
#include <vector>

// Запит 1: Отримати лікарів за спеціальністю та закладом
void query1_getDoctorsBySpecialtyAndInstitution(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::string& specialty, int institutionId);

// Запит 2: Отримати обслуговуючий персонал за посадою та закладом
void query2_getSupportStaffByRoleAndInstitution(
    const std::vector<std::shared_ptr<SupportStaff>>& staff,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::string& role, int institutionId);

// Запит 3: Отримати лікарів за спеціальністю та мінімальною кількістю операцій
void query3_getDoctorsBySpecialtyAndMinOperations(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::string& specialty, int minOperations, int institutionId);

// Запит 4: Отримати лікарів за спеціальністю та мінімальним стажем
void query4_getDoctorsBySpecialtyAndMinExperience(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::string& specialty, int minExperienceYears, int institutionId);

// Запит 5: Отримати лікарів за спеціальністю та науковим ступенем
void query5_getDoctorsBySpecialtyAndAcademicTitle(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::string& specialty, int institutionId);

// Запит 6: Отримати пацієнтів за місцем перебування
void query6_getPatientsByLocation(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Ward>>& wards, int institutionId,
    const std::string& department, int wardId);

// Запит 7: Отримати пацієнтів за періодом лікування
void query7_getPatientsByTreatmentPeriod(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Ward>>& wards, int institutionId,
    int wardId, int doctorId, const std::tm& startDate, const std::tm& endDate);

// Запит 8: Отримати пацієнтів у лікаря за профілем в поліклініці
void query8_getPatientsByDoctorSpecialtyAndPolyclinic(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::string& doctorSpecialty, int polyclinicId);

// Запит 9: Отримати ліжка за статусом та закладом
void query9_getTotalBedsByInstitutionAndStatus(
    const std::vector<std::shared_ptr<Ward>>& wards,
    const std::vector<std::shared_ptr<Bed>>& beds,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int institutionId, BedStatus status);

void query10_getRoomsAndVisitsByPolyclinic(
    const std::vector<std::shared_ptr<Room>>& rooms,
    const std::vector<std::shared_ptr<RoomVisit>>& roomVisits,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int polyclinicId, const std::tm& startDate, const std::tm& endDate);

void query11_getDoctorProductivity(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<RoomVisit>>& roomVisits,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int doctorId, int polyclinicId, const std::string& specialty,
    const std::tm& startDate, const std::tm& endDate);

void query12_getDoctorWorkload(
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int doctorId, int hospitalId, const std::string& specialty);

void query13_getPatientsWithOperations(
    const std::vector<std::shared_ptr<Patient>>& patients,
    const std::vector<std::shared_ptr<Operation>>& operations,
    const std::vector<std::shared_ptr<Doctor>>& doctors,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int hospitalId, int polyclinicId, int doctorId, const std::tm& startDate,
    const std::tm& endDate);

void query14_getLabProductivity(
    const std::vector<std::shared_ptr<LabTest>>& labTests,
    const std::vector<std::shared_ptr<MedicalInstitution>>& institutions,
    int institutionId, const std::tm& startDate, const std::tm& endDate);
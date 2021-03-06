#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <unordered_map>

#include "assignment.hpp"
#include "id.hpp"
#include "reference.hpp"
#include "solution.hpp"
#include "student.hpp"

class database {
public:
	database() = default;
	database(const std::string& filename) {load(filename);}
	void load(const std::string& filename);
	void save(const std::string& filename);
	
	assignment& get_assignment(assignment_id);
	student& get_student(student_id);
	solution& get_solution(solution_id);
	
	const assignment& get_assignment(assignment_id) const;
	const student& get_student(student_id) const;
	const solution& get_solution(solution_id) const;
	
	void add_assignment(assignment new_assignment);
	void add_student(student new_student);
	void add_solution(solution new_solution);
	
	std::vector<reference<const student>> get_student_list() const;
	std::vector<reference<student>> get_student_list();
	std::vector<student_id> get_student_id_list() const;
	
	unsigned max_total_points() const;
	const std::vector<std::pair<double, std::string>>& achievments() const {return m_achievements;}
	
	solution_id new_solution_id();
	
	std::vector<student_id> parse_students_string(const std::string& str) const;
	void make_team(const std::vector<student_id>& students);
	
	void scrample_pseudonyms();
private:
	std::unordered_map<student_id, student> m_students;
	std::unordered_map<solution_id, solution> m_solutions;
	std::unordered_map<assignment_id, assignment> m_assignments;
	std::vector<std::pair<double, std::string>> m_achievements;
	std::uint32_t m_highest_solution_id = 0;
};

#endif

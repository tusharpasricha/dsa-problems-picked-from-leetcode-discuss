// 1. The Perfect Team
// The School of Languages and Science teaches five subjects: Physics, Chemistry, Math, Botany, and Zoology. Each student is skilled in one subject. The skills of the students are described by string of named skills that consists of the letters p, c, m, b, and z only. Each character describes the skill of a student.
// Given a list of students' skills, determine the total number of different teams satisfying the following constraints:
// • A team consists of a group of exactly five students.
// • Each student is skilled in a different subject.
// • A student may only be on one team.
// example 1
// skills = pcmbzpcmbz
// There are 2 possible teams that can be formed at one time: skills[0-4] = pcmbz and
// skills[5-9] = pcmbz, for example.
// Example 2
// skills = mppzbmbpzcbmpbmczcz
// The sorted string is bbbbcccmmmmppppzzzz. All of the skills are represented, but there are only 3 students skilled in Chemistry. Only 3 teams can be created.
// Function Description
// Complete the function differentTeams in the editor below. The function must return an integer value representing the number of teams that can be formed given the constraints.
// differentTeams has the following parameter(skills):
// string skills: a string of length n where each position represents the skill of a student
// Constraints
// • 5≤n≤ 5 x 105
// • skills[i] are in the set (p,c,m, b,z)
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int differentTeams2(const string& skills){
    map<char,int> freq;
    for (int i = 0; i < skills.size(); i++) {
        freq[skills[i]]++;
    }
    return min({freq['p'], freq['c'], freq['m'], freq['b'], freq['z']});
 ;
}

// std::map is implemented as a balanced binary search tree (typically a Red-Black Tree), each insertion and access operation takes O(log k), where 
// k is the number of distinct characters inserted into the map (in this case, at most 26 since there are 26 letters in the alphabet).

// So, iterating over the string and updating the map takes O(n \log k), where 
// n is the length of the string, and k is at most 26.

// Since 
// k is constant and doesn't grow with the input size, the time complexity can be simplified to O(n \log 26), which is O(n).
// Time Complexity: ( O(n) )
// Space Complexity: ( O(1) )

int differentTeams(string skills) {

    int p =0;
    int c = 0;
    int m = 0;
    int b = 0;
    int z = 0;

    for(int i=0;i<skills.size();i++){
        if(skills[i] == 'p'){
            p++;
        }
        else if (skills[i] == 'c'){
            c++;
        }
        else if(skills[i] == 'm'){
            m++;
        }
        else if (skills[i] == 'b'){
            b++;
        }
        else{
            z++;
        }
    }

    return min(p,min(c,min(m,min(b,z))));
}
// Time Complexity: O(n)
// Space Complexity: O(1)
int main(){
    string skills = "mppzbmbpzcbmpbmczcz";
    cout << differentTeams2(skills);
}


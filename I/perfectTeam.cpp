#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string s = "mppzbmbpzcbmpbmczcz";
    map<char, int> freq;
    
    // Initialize the map with the characters you are interested in
    freq['p'] = 0;
    freq['c'] = 0;
    freq['m'] = 0;
    freq['b'] = 0;
    freq['z'] = 0;
    
    // Iterate through the string and count frequencies
    for (int i = 0; i < s.size(); i++) {
        if (freq.find(s[i]) != freq.end()) {
            freq[s[i]]++;
        }
    }
    
    // Find the minimum frequency
    cout << min(freq['p'],min(freq['c'],min(freq['m'],min(freq['b'],freq['z']))));
    
}

// #include <iostream>
// using namespace std;
// int main(){
//     string s = "mppzbmbpzcbmpbmczcz";
//     int p =0;
//     int c = 0;
//     int m = 0;
//     int b = 0;
//     int z = 0;

//     for(int i=0;i<s.size();i++){
//         if(s[i] == 'p'){
//             p++;
//         }
//         else if (s[i] == 'c'){
//             c++;
//         }
//         else if(s[i] == 'm'){
//             m++;
//         }
//         else if (s[i] == 'b'){
//             b++;
//         }
//         else{
//             z++;
//         }
//     }

//     cout << min(p,min(c,min(m,min(b,z))));
// }


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
// differentTeams has the following parameter(s):
// string skills: a string of length n where each position represents the skill of a student
// Constraints
// • 5≤n≤ 5 x 105
// • skills[i] are in the set (p,c,m, b,z)
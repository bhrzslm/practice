#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::stringstream;
using std::ws;
using std::vector;
using std::bitset;

void createOriginalFile (const vector<vector<bool > > &);
bool testConcat (const vector<vector<bool > >&, int, int, const vector<bool> &);
bool checkNode (const vector<vector<bool> >&, const vector<vector<int> >&, vector<int>&, const vector<bool>&);

int main (void){
  int number_of_cases, bla;
  cin >> number_of_cases >> ws;
  
  for (int counter = 0; counter < number_of_cases; counter++)
    {
      vector<vector<bool> > fragments;
      string line;
      getline(cin, line);

      while (!line.empty()){
	vector<bool> fragment;
	for (string::iterator itr = line.begin(), endItr = line.end(); itr != endItr; itr++)
	  fragment.push_back(((*itr) == '1' ? true : false));

	fragments.push_back(fragment);
	getline (cin, line);
      }
      
      createOriginalFile (fragments);
    }
  
  return 0;
}

void createOriginalFile (const vector<vector<bool> > & fragments){
  //TODO write this function
}

/** 
 * Checks if this node in the search tree could lead to a feasible
 * solution
 * 
 * @param fragments all fragments
 * @param possible_matches for everyfragment, an int vector of indices of
 *        other possible matches
 * @param matched the indices of those which are matched
 * @param file the pattern 
 * 
 * @return whether or not this partial assignment could lead to a solution
 */
bool checkNode (const vector<vector<bool> >& fragments, const vector<vector<int> >& possible_matches, vector<int>& matched, const vector<bool>& file){
  
  /// If everything is matched, return true 
  vector<int> unmatched;
  int counter = 0;
  for (vector<int>::iterator itr = matched.begin() , end = matched.end(); itr != end; itr++, counter++)
    if (*itr == -1)
      unmatched.push_back(counter);

  if (unmatched.empty()) 
    return true;


  ///  for any of the unmatched fragments
  for (vector<int>::iterator unmatched_itr = unmatched.begin(), end = unmatched.end(); unmatched_itr != end; unmatched_itr++)

  // for any of the possible matches for that fragment (which are not already matched)
    for (vector<int>::const_iterator matches_itr = possible_matches[*unmatched_itr].begin() , m_itr_end = possible_matches[*unmatched_itr].end(); matches_itr != m_itr_end; matches_itr++)
      if (matched[*matches_itr] == -1)
  // if the match works for any of the two directions (concatenation to right/left)
        if (testConcat (fragments, *matches_itr, *unmatched_itr, file))
  // mark the two as matched
        {
          matched[*unmatched_itr] = *matches_itr;
          matched[*matches_itr] = *unmatched_itr;
  // call the function again
          if (checkNode(fragments, possible_matches, matched, file))
            return true;
  // erase the marks
          matched[*unmatched_itr] = -1;
          matched[*matches_itr] = -1;
        }

  return false;
}

/** 
 * Tests both possible concatenations of two fragments to see if they
 * can form the given string together
 * 
 * @param fragments the vector of all fragments
 * @param index1 the index of first fragment in fragments vector
 * @param index2 the index of second fragment in fragments vector
 * @param file the desired string to be formed 
 * 
 * @return whether or not the concatenation of two fragments could form the
 *         desired string
 */
bool testConcat (const vector<vector<bool > >& fragments, int index1, int index2, const vector<bool> & file){
  //TODO write this function
  return false;
}

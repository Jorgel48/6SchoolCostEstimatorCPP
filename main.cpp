/*
Dr. Tyson McMillan School Cost Estimator Using C++. Students were tasked with creating a C++ program from an operational Excel Spreasheet. 
Nov 14, 2019
*/
#include <iostream>
#include <string>
using namespace std; 
/*
Implementation of Option 4 Keep it Simple	
class	Semester
int main	3 instances of semester ft, pt, ht
int main has constant	Declare constants for all those constants values, semstersInAYear, hoursPerClass,
	Ask the user to populate the constants
*/

class Semester
{
  private:
  //systems assumptions constants
  //static const variables keep their value even after multiple calls
    static const int hoursPerClass = 3; 
    static const int monthsInOneSemester = 4;
    static const int semestersInAYear = 3; 
    //user changeable settings (need: setters and getters)
    int hoursTheStudentTakes; 
    int hoursInTheDegree; 
    string schoolName; 
    double costPerCreditHour; 
    double bookCostsPerClass;
    double roomAndBoardCosts; 
    double foodCostsPerMonth; 
    double travelCostsPerMonth; 
  public:
    Semester() //default constructor TCC
    {
        //user changeable settings default values
        hoursTheStudentTakes = 0; //ft 12, pt 9, ht 6
        hoursInTheDegree = 60; 
        schoolName = "TCC"; 
        costPerCreditHour = 64.00; 
        bookCostsPerClass = 100.00;
        roomAndBoardCosts = 1000.00; 
        foodCostsPerMonth = 150.00; 
        travelCostsPerMonth = 90.00; 
    } 
    //paramerterize constructor with initizlier list
    Semester(int hTST, int hID, string sN, double cPCH, double bCPC, double rABC, double fCPM, double tCPM) : 
    hoursTheStudentTakes(hTST), hoursInTheDegree(hID),
    schoolName(sN), costPerCreditHour(cPCH),
    bookCostsPerClass(bCPC), roomAndBoardCosts(rABC),
    foodCostsPerMonth(fCPM), travelCostsPerMonth(tCPM)
    { }
    void setHoursAStudentTakes(int h) { hoursTheStudentTakes = h; }
    int getHoursAStudentTakes() const { return hoursTheStudentTakes; }
    //write setters and getters for the other non constant member varibles
    void setHoursInTheDegree(int h) {
      hoursInTheDegree = h;
    }

    int getHoursInTheDegree() {
      return hoursInTheDegree;
    }

    void setSchoolName(string s) {
      schoolName = s;
    }
    string getSchoolName() {
      return schoolName;
    }

    void setCostPerCreditHour(double c) {
      costPerCreditHour = c;
    }

    double getCostPerCreditHour() {
      return costPerCreditHour;
      
    }

    void setBookCostsPerClass(double c) {
      bookCostsPerClass = c;
    }

    double getBookCostsPerClass() {
      return bookCostsPerClass;
    }
    
    void setRoomAndBoardCosts(double r) {
      roomAndBoardCosts = r;
    }

    double getRoomAndBoardCosts() {
      return roomAndBoardCosts;
    }

    void setFoodCostsPerMonth(double f) {
      foodCostsPerMonth = f;
    }

    double getFoodCostsPerMonth() {
      return foodCostsPerMonth;
    }

    void setTravelCostsPerMonth(double t) {
      travelCostsPerMonth = t;
    }

    double getTravelCostsPerMonth() {
      return travelCostsPerMonth;
    }

    //calculate tution
    double calculateTuition()
    {
      return (hoursTheStudentTakes * costPerCreditHour); 
    }

    //calculate room and board
    double calculateRoomAndBoard()
    {
      return (monthsInOneSemester * roomAndBoardCosts); 
    }

    //caculate travel
    double calculateTravelCost() {
      return monthsInOneSemester * travelCostsPerMonth;
    }

    //calculate food
    double calculateFoodCost() {
      return monthsInOneSemester * foodCostsPerMonth;
    }



    //calcualte books
    double calculateBookCosts() {
      return (hoursTheStudentTakes / hoursPerClass) * bookCostsPerClass;
    }
    //calcualte and return semester costs 
    double calculateSemesterCost() {
      return calculateBookCosts() + calculateTravelCost() + calculateFoodCost();
    }

    //print Semester 

    //calculate total cost per semester
    double calculateTotalCostPerSemester()
    {
      return ( calculateTuition() + calculateRoomAndBoard() + calculateSemesterCost()); 
    }
};

int main() 
{
    //local assumptions for user input
    const int hoursAFullTimeStudent = 12;
    const int hoursAPartTimeStudent = 9;
    const int hoursAHalfTimeStudent = 6;
   
   //instances of the 3 types of semesters
   Semester ftTCC; //call default constructor
   Semester ptTCC; //calls default constuctor 
   Semester htTCC; //call default constructor

   //set hours a student a student takes per semester types
   ftTCC.setHoursAStudentTakes(hoursAFullTimeStudent);
   ptTCC.setHoursAStudentTakes(hoursAPartTimeStudent);
   htTCC.setHoursAStudentTakes(hoursAHalfTimeStudent);

   //allow the user to populate the paramerterized constuctor
   //ask for the values, and pass them as arguments. '
   int hID;
   string sN;
   double cost;
   double book;
   double room;
   double food;
   double travel;
   
   cout << "How many hours in the degree?: ";
   cin >> hID;
   cout << "What is the school name?: ";
   cin >> sN;
   cout << "What is the cost per credit hour: ";
   cin >> cost;
   cout << "What is the book cost per class: ";
   cin >> book;
   cout << "What is the in room and board: ";
   cin >> room;
   cout << "What is the food cost per month: ";
   cin >> food;
   cout << "What is the travel cost per month: ";
   cin >> travel;
   Semester ftCollege(hoursAFullTimeStudent, hID, sN, cost, book, room, food, travel);
   //print the results
   cout << "Hours in degree: " << ftCollege.getHoursInTheDegree() << endl;
   cout << "School Name: " << ftCollege.getSchoolName() << endl;
   cout << "Cost per credit hour: " << ftCollege.getCostPerCreditHour() << endl;
   cout << "Book cost per class: " << ftCollege.getBookCostsPerClass() << endl;
   cout << "Room and Baord cost: " << ftCollege.getRoomAndBoardCosts() << endl;
   cout << "Food cost per month: " << ftCollege.getFoodCostsPerMonth() << endl;
   cout << "Travel cost: " << ftCollege.getTravelCostsPerMonth() << endl;
   Semester ptCollege(hoursAFullTimeStudent, hID, sN, cost, book, room, food, travel);
   //print the results
   cout << "Hours in degree: " << ptCollege.getHoursInTheDegree() << endl;
   cout << "School Name: " << ptCollege.getSchoolName() << endl;
   cout << "Cost per credit hour: " << ptCollege.getCostPerCreditHour() << endl;
   cout << "Book cost per class: " << ptCollege.getBookCostsPerClass() << endl;
   cout << "Room and Baord cost: " << ptCollege.getRoomAndBoardCosts() << endl;
   cout << "Food cost per month: " << ptCollege.getFoodCostsPerMonth() << endl;
   cout << "Travel cost: " << ptCollege.getTravelCostsPerMonth() << endl;
   Semester htCollege(hoursAFullTimeStudent, hID, sN, cost, book, room, food, travel);
   //print the results
   cout << "Hours in degree: " << htCollege.getHoursInTheDegree() << endl;
   cout << "School Name: " << htCollege.getSchoolName() << endl;
   cout << "Cost per credit hour: " << htCollege.getCostPerCreditHour() << endl;
   cout << "Book cost per class: " << htCollege.getBookCostsPerClass() << endl;
   cout << "Room and Baord cost: " << htCollege.getRoomAndBoardCosts() << endl;
   cout << "Food cost per month: " << htCollege.getFoodCostsPerMonth() << endl;
   cout << "Travel cost: " << htCollege.getTravelCostsPerMonth() << endl;
   
    //Semester(int hTST, int hID, string sN, double cPCH, double bCPC, double rABC, double fCPM, double tCPM)  
   //pass Semester Objects by reference to display summary results via function 

   //calcuate and display tuition for each object in the program 
   cout << "Full time tuition at TCC: " << ftTCC.calculateTuition() << endl; 
   cout << "Part time tuition at TCC: " << ptTCC.calculateTuition() << endl; 
   cout << "Half time tuition at TCC: " << htTCC.calculateTuition() << endl; 
   cout << "Full time tuition at college" << ftCollege.calculateTuition() << endl; 
   cout << "Part time tuition at college" << ptCollege.calculateTuition() << endl; 
   cout << "Half time tuition at college" << htCollege.calculateTuition() << endl; 

   
   //calculate and display room and board costs for each object in the program 
   cout << "Full time room and board at TCC: " << ftTCC.calculateRoomAndBoard() << endl; 
   cout << "Part time room and board at TCC: " << ptTCC.calculateRoomAndBoard() << endl; 
   cout << "Half time room and board at TCC: " << htTCC.calculateRoomAndBoard() << endl; 
   cout << "Full time room and board at college: " << ftCollege.calculateRoomAndBoard() << endl; 
   cout << "Part time room and board at college: " << ptCollege.calculateRoomAndBoard() << endl; 
   cout << "Half time room and board at college" << htCollege.calculateRoomAndBoard() << endl; 

 //calculate the respective cost per semester for each student type
  cout << "Full time cost per semester at TCC" << ftTCC.calculateTotalCostPerSemester() << endl;
  cout << "Part time cost per semester at TCC" << ptTCC.calculateTotalCostPerSemester() << endl;
  cout << "Half time cost per semester at TCC" << htTCC.calculateTotalCostPerSemester() << endl;
 cout << "Full time cost per semester at college" << ftCollege.calculateTotalCostPerSemester() << endl;
 cout << "Part time cost per semester at college" << 
 ptCollege.calculateTotalCostPerSemester() << endl;
 cout << "Half time cost per semester at college" << 
 htCollege.calculateTotalCostPerSemester() << endl;
  return 0; 
}
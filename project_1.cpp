// https://learn.uwaterloo.ca/d2l/le/content/1054276/viewContent/5683399/View

#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// NO ARRAYS

double input_max_grade(string s)
{
       double max;
       do
       {
              std::cout << "Enter the maximum " + s + " grade: ";
              std::cin >> max;
       } while (max <= 0 || max != std::round(max));
       return max;
}

double input_your_grade(string s, double max)
{
       double g;
       do
       {
              std::cout << "Enter your " << s << " grade: ";
              std::cin >> g;
       } while (!(g >= 0 && g <= max));
       return g;
}

int main();

int main()
{
       // Local variables
       double f_max, m_max, p1_max, p2_max, p3_max, p4_max, p5_max, f_achieved, f_100, m_achieved, m_100, p1_achieved,
           p1_100, p2_achieved, p2_100, p3_achieved, p3_100, p4_achieved, p4_100, p5_achieved, p5_100, e_100, p_100;

       // Input maximum grade and grade
       // max (>0), then achieved (0<grade<=max)
       f_max = input_max_grade("final examination");
       f_achieved = input_your_grade("final examination", f_max);
       m_max = input_max_grade("mid-term examination");
       m_achieved = input_your_grade("mid-term examination", m_max);
       p1_max = input_max_grade("project 1");
       p1_achieved = input_your_grade("project 1", p1_max);
       p2_max = input_max_grade("project 2");
       p2_achieved = input_your_grade("project 2", p2_max);
       p3_max = input_max_grade("project 3");
       p3_achieved = input_your_grade("project 3", p3_max);
       p4_max = input_max_grade("project 4");
       p4_achieved = input_your_grade("project 4", p4_max);
       p5_max = input_max_grade("project 5");
       p5_achieved = input_your_grade("project 5", p5_max);

       // Convert to percentage
       f_100 = 100 * (f_achieved / f_max);
       m_100 = 100 * (m_achieved / m_max);
       p1_100 = 100 * (p1_achieved / p1_max);
       p2_100 = 100 * (p2_achieved / p2_max);
       p3_100 = 100 * (p3_achieved / p3_max);
       p4_100 = 100 * (p4_achieved / p4_max);
       p5_100 = 100 * (p5_achieved / p5_max);

       if (m_100 < f_100)
              m_100 = f_100;
       if (p1_100 < f_100)
              p1_100 = f_100;
       if (p2_100 < f_100)
              p2_100 = f_100;
       if (p3_100 < f_100)
              p3_100 = f_100;
       if (p4_100 < f_100)
              p4_100 = f_100;
       if (p5_100 < f_100)
              p5_100 = f_100;

       // Examination weighting average
       e_100 = 0.75 * f_100 + 0.25 * m_100;

       // Calculating project grade
       p_100 = (p1_100 + p2_100 + p3_100 + p4_100 + p5_100) / 5;

       // Final grade calculation
       if (e_100 <= 40)
              std::cout << std::round(e_100 + 1e-12);
       else if (e_100 >= 60)
              std::cout << std::round(((2.0 / 3) * e_100 + (1.0 / 3) * p_100) + 1e-12);
       else
              std::cout << std::round((p_100 * (1.0 / 3) * ((e_100 - 40) / 20) + e_100 * (1 - ((1.0 / 3) * ((e_100 - 40) / 20)))) + 1e-12);

       return 0;
}
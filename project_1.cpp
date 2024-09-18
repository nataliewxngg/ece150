// https://learn.uwaterloo.ca/d2l/le/content/1054276/viewContent/5683399/View

#include <iostream>
#include <cmath>
// NO ARRAYS

int main();

int main()
{
       // Local variables
       double f_max, m_max, p1_max, p2_max, p3_max, p4_max, p5_max, f_achieved, f_100, m_achieved, m_100, p1_achieved,
           p1_100, p2_achieved, p2_100, p3_achieved, p3_100, p4_achieved, p4_100, p5_achieved, p5_100, e_100, p_100;

       // Input maximum grade and grade
       // max (>0), then achieved (0<grade<=max)

       // Exam
       do
       {
              std::cout << "Enter the maximum final examination grade: ";
              std::cin >> f_max;
       } while (f_max <= 0 || f_max != std::round(f_max));

       do
       {
              std::cout << "Enter your final examination grade: ";
              std::cin >> f_achieved;
       } while (!(f_achieved >= 0 && f_achieved <= f_max));

       // Midterms
       do
       {
              std::cout << "Enter the maximum mid-term examination grade: ";
              std::cin >> m_max;
       } while (m_max <= 0 || m_max != std::round(m_max));

       do
       {
              std::cout << "Enter your mid-term examination grade: ";
              std::cin >> m_achieved;
       } while (!(m_achieved >= 0 && m_achieved <= m_max));

       // P1
       do
       {
              std::cout << "Enter the maximum project 1 grade: ";
              std::cin >> p1_max;
       } while (p1_max <= 0 || p1_max != std::round(p1_max));

       do
       {
              std::cout << "Enter your project 1 grade: ";
              std::cin >> p1_achieved;
       } while (!(p1_achieved >= 0 && p1_achieved <= p1_max));

       // P2
       do
       {
              std::cout << "Enter the maximum project 2 grade: ";
              std::cin >> p2_max;
       } while (p2_max <= 0 || p2_max != std::round(p2_max));

       do
       {
              std::cout << "Enter your project 2 grade: ";
              std::cin >> p2_achieved;
       } while (!(p2_achieved >= 0 && p2_achieved <= p2_max));

       // P3
       do
       {
              std::cout << "Enter the maximum project 3 grade: ";
              std::cin >> p3_max;
       } while (p3_max <= 0 || p3_max != std::round(p3_max));

       do
       {
              std::cout << "Enter your project 3 grade: ";
              std::cin >> p3_achieved;
       } while (!(p3_achieved >= 0 && p3_achieved <= p3_max));

       // P4
       do
       {
              std::cout << "Enter the maximum project 4 grade: ";
              std::cin >> p4_max;
       } while (p4_max <= 0 || p4_max != std::round(p4_max));

       do
       {
              std::cout << "Enter your project 4 grade: ";
              std::cin >> p4_achieved;
       } while (!(p4_achieved >= 0 && p4_achieved <= p4_max));

       // P5
       do
       {
              std::cout << "Enter the maximum project 5 grade: ";
              std::cin >> p5_max;
       } while (p5_max <= 0 || p5_max != std::round(p5_max));

       do
       {
              std::cout << "Enter your project 5 grade: ";
              std::cin >> p5_achieved;
       } while (!(p5_achieved >= 0 && p5_achieved <= p5_max));

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
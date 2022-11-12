/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package P12;

import java.lang.Comparable;

/**
 * @author Talha Rao
 * @due March 28, 2022
 * @assignment Assignment 8
 */
public class Student
{

    String name;
    String lastName;
    int studentNo;
    double gpa;

    public int compareTo(Student stu)
    {
        if (name.equals(stu.name) && lastName.equals(stu.lastName) && studentNo == stu.studentNo && gpa == stu.gpa)
        {
            return 0;
        } else if (gpa < stu.gpa)
        {
            return -1;
        } else
        {
            return +1;
        }
    }
}

package ems;

import java.util.Scanner;

public class EMS {

    public static void main(String[] args) {
        
        System.out.println("Welcome to Employee Management System\n\n");
        Scanner sc=new Scanner(System.in);
                
        while(true)
        {
            System.out.println("1. Add");
            System.out.println("2. Search");
            System.out.println("3. Delete\n");
            
            int choice=sc.nextInt();
            
            if(choice==1)
            {
                System.out.println("1. Director");
                System.out.println("2. Manager");
                System.out.println("3. Trainer\n");
                
                int sec_ch=sc.nextInt();
                
                if(sec_ch==1)
                {
                    System.out.println("Enter Id");
                    int id=sc.nextInt();
                    System.out.println("Enter Name");
                    String name=sc.next();
                    String type="DIR";
                    System.out.println("Enter Director DIN");
                    int din=sc.nextInt();
                    System.out.println("Enter Director Incentive");
                    int incentive=sc.nextInt();
                    
                    Director dir=new Director();
                    dir.add(id,name,type,din,incentive);
                    System.out.println("Director Added Successfully");
                }
                else if(sec_ch==2)
                {
                    System.out.println("Enter Id");
                    int id=sc.nextInt();
                    System.out.println("Enter Name");
                    String name=sc.next();
                    String type="MAN";
                    System.out.println("Enter Manager Team Size");
                    int team_size=sc.nextInt();
                    System.out.println("Enter Manager Department");
                    String department=sc.next();
                    
                    Manager man=new Manager();
                    man.add(id,name,type,team_size,department);
                    System.out.println("Manager Added Successfully");
                }
                else if(sec_ch==3)
                {
                    System.out.println("Enter Id");
                    int id=sc.nextInt();
                    System.out.println("Enter Name");
                    String name=sc.next();
                    String type="TRA";
                    System.out.println("Enter Trainer Student's Count");
                    int st_count=sc.nextInt();
                    System.out.println("Enter Trainer's Technology");
                    String technology=sc.next();
                    
                    Trainer tra=new Trainer();
                    tra.add(id,name,type,st_count,technology);
                    System.out.println("Trainer Added Successfully");
                }
                else
                {
                    System.out.println("Invalid Choice");
                }
                
            }
            
            else if(choice==2)
            {
                System.out.println("Enter Employee ID to search");
                int empId=sc.nextInt();
               
                String empType=Employee.getEmpType(empId);
                
                if(empType=="DIR")
                {
                    Director dir=new Director();
                    dir.getDetails(empId);
                    System.out.println("Id : "+dir.getEmpId());
                    System.out.println("Name : "+dir.getEmpName());
                    System.out.println("Type : "+dir.getEmpType());
                    System.out.println("DIN : "+dir.getDin_num());
                    System.out.println("Incentive : "+dir.getIncentive());
                }
                else if(empType=="MAN")
                {
                    Manager man=new Manager();
                    man.getDetails(empId);
                    System.out.println("Id : "+man.getEmpId());
                    System.out.println("Name : "+man.getEmpName());
                    System.out.println("Type : "+man.getEmpType());
                    System.out.println("Team Size : "+man.getTeam_size());
                    System.out.println("Department : "+man.getDepartment());
                }
                else if(empType=="TRA")
                {
                    Trainer tra=new Trainer();
                    tra.getDetails(empId);
                    System.out.println("ID : "+tra.getEmpId());
                    System.out.println("Name : "+tra.getEmpName());
                    System.out.println("Type : "+tra.getEmpType());
                    System.out.println("Student Count : "+tra.getStudent_count());
                    System.out.println("Technology : "+tra.getTechnology());
               }
                
            }
            
            else if(choice ==3)
            {
                
               System.out.println("Delete not yet available"); 
              
            }
            
            else
            {
                System.out.println("Invalid Choice");
            }
            
        }
        
    }
    
}

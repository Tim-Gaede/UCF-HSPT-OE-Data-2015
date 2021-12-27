import java.util.*;
import java.io.*;
public class how {
    public static void main(String[] args) throws IOException{
        Scanner br = new Scanner(System.in);
        int t = br.nextInt();
        for(int caseOn = 1;caseOn<=t;caseOn++){
            int teams1 = br.nextInt();
            int teams2 = br.nextInt();
            //Stores all the teams from both scoreboards in one array
            Team[] teams = new Team[teams1+teams2];
            for(int i = 0;i<teams1;i++){
                teams[i] = new Team(br.next(), br.nextInt(), br.nextInt());
            }
            for(int i = 0;i<teams2;i++){
                teams[i+teams1] = new Team(br.next(), br.nextInt(), br.nextInt());
            }
            //Use the built in sort to sort the teams
            //Runs in about n*log(n) time where n is the size of the array
            Arrays.sort(teams);
            System.out.println("Competition #"+caseOn+":");
            for(int i = 1;i<=teams1+teams2;i++){
                System.out.println(i+" "+teams[i-1].toString());
            }
            System.out.println();
        }
    }
    //Team object stores information about the team
    //Making it comparable allows for easy use of the fast built in java sort
    public static class Team implements Comparable<Team>{
        String name;
        int problems, penalty;
        public Team(String s, int a, int b){
            name = s;
            problems = a;
            penalty = b;
        }
        public int compareTo(Team o){
            if(problems == o.problems){
                return penalty-o.penalty;
            }
            return o.problems-problems;
        }
        //Used for printing out the teams
        public String toString(){
            return name+" "+problems+" "+penalty;
        }
    }
}

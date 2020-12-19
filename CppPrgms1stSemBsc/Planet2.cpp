// Program for calculating time between reversing of relative velocity vector of two planets.
//Created by Nitish Arya on 30 October

#include<math.h>
#include<iostream>

#define pi 3.14159265

using namespace std;


int main()
{
	
	float val,x,result,upd1,upd2;
    
    float vP1,vP2,dirP1,dirP2;            //Velocities(tangential) of the two planets with direction.
    
    float time=0,radius1,radius2,alpha;
    
            
    for(int i=0;i<20;i++)cout<<"*";
    cout<<"Welcome to time calculation machine";
    for(int i=0;i<20;i++)cout<<"*";
    for(int i=0;i<3;i++){cout<<"\n";}
     
    cout<<"This machine calculates time ";
     
    cout<<"between reversing of relative velocity vector of    two planets.\n";
    
    for(int i=0;i<2;i++){cout<<"\n";}
    
    for(int i=0;i<20;i++)cout<<" "; 
    cout<<"#";
    cout<<"{Assume their paths to be CIRCULAR.}\n\n";
    cout<<"**WAIT FOR THE PROGRAM TO CALCULATE RESULT AFTER ENTERING THE VALUES**\n\n";
    
    for(int i=0;i<2;i++){cout<<"\n";}
     
    cout<<"Enter details of planet one.\n";    //Input details of Planet one.
     
    cout<<"\nRadius from sun(in km):";
    cin>>radius1;radius1=radius1*1000;  //Converting radius in meters for calculations.
    
    cout<<"\nLinera velocity of the Planet(in km/s) (assuming this planet to be at origin ):";
    cin>>vP1;  
    vP1=vP1*1000;
            
    for(int i=0;i<2;i++){cout<<"\n";}
    
    cout<<"Enter details of planet two.\n\n";    //Input details of Planet two.
    
    cout<<"Radius from sun(in km):";cin>>radius2;
    radius2=radius2 * 1000;      //Converting radius in meters for calculations.

    
    
    cout<<"\nLinera velocity of the Planet(in km/s) with the angle(in degrees) it(vector)     makes from positive x-axis(assuming Planet1 at the origin):";
    cin>>vP2;
    
    cout<<"\nEnter angle:";
    cin>>dirP2;   //Since we have fixed co-ordinate axes fixing origin at Planet1, this angle will be the angle between thier velocity vectors.
    
    vP2 = vP2*1000;
    
    
    if((dirP2<90)||(dirP2==90)||(dirP2==0))
        dirP2 = dirP2+90;
    
    else
        dirP2 = 270 - dirP2;
        
    
    
    for(int i=0;i<2;i++){cout<<"\n";}
    
        
    val= atan(( vP1 * sin((dirP2) * pi/180)) / ( vP2 + vP1 * cos((dirP2) * pi/180)) ) * 180/pi;
    
    cout<<val<<"\n";
    
    //Sending radian value of angle in sin and cos.
    //Calculating angle between the relative velocity and Planet1 by vector formula.
    //Formula obtained angle is converted to degrees from radians.              
    
    dirP1 = -90;
    
    if(dirP2>90)
      val = -val;

    alpha = val+dirP1;
    
    if(alpha<-180)
      alpha = 360 + alpha;
        
    upd1 = alpha;
    
    cout<<"\nInitial angle between the relative velocity(of Planet2 w.r.t 1) with the x-axis:";
    cout<<"\""<<alpha<<"\""<<"\n\n";
     
    
    do
     {  
		upd1 = upd1 + (vp1/radius1)*180/pi;
		
		time++;
		
	
      } while(alpha!=(-result));
    
    for(int i=0;i<2;i++){cout<<"\n";}
    
     
    cout<<"\nTime after which the person on planet one will see the planet two going in    reverse direction is:";
    cout<<"\nIn seconds:\""<<time<<"\"";
    cout<<"\nIn hours:\""<<time/3600<<"\"";
    cout<<"\nIn days:\""<<time/(3600*24)<<"\"";
    cout<<"\nIn years:\""<<time/(3600*24*365)<<"\"";  
      
} 
   
    
    
    
    
    
    
    
    
    
    
    
    

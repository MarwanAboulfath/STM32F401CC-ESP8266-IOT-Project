<?php

if(isset($_GET['status']))
{
     $my_file=fopen("../status.txt","w");   
     if($_GET['status']=='on')
          {
              fwrite($my_file,'1');
			  header("Location:/files/on.html");
          }
        else if($_GET['status']=='off')
          {
                fwrite($my_file,'0');
			  header("Location:/files/off.html");
          }
        fclose($my_file);
                
}







?>
<?php 
  
function binarySearch($arr, $v) 
{ 
    if (count($arr) === 0) return false; 
    $low = 0; 
    $high = count($arr) - 1; 
      
    while ($low <= $high) { 

        $mid = floor(($low + $high) / 2); 

        if($arr[$mid] == $v) { 
            return true; 
        } 
  
        if ($v < $arr[$mid]) { 
            $high = $mid -1; 
        } 
        else { 
            $low = $mid + 1; 
        } 
    } 
    return false; 
} 
  
// Usage
$arr = array(1, 2, 3, 4, 5); 
$value = 5; 
if (binarySearch($arr, $value) == true) { 
    echo $value . " exists"; 
} 
else { 
    echo $value . " Doesn't exist"; 
}

let array = ["Hacktoberfest","Happy","Digital","Hacktober","Ocean",":)","2019"]
let a = ""
let b = ""
  for(i=0;i<array.length;i++){
    if(i%2==0){
      a += " " + array[i]
    }else{
      b += " " + array[i]
    }
  }
console.log(a)
console.log(b)
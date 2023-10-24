const powerSet = function(nums){
    const output =[];
    const helper = function(nums,i,subset){
        if(i===nums.length){
            output.push(subset.slice());
            return;
        }
        //dont add
        helper(nums,i+1,subset);
        //add
        subset.push(nums[i]);
        helper(nums,i+1,subset);
        subset.pop();
    }
    helper(nums,0,[]);
    return output;
}

powerSet([9]);

var findMedianSortedArrays = function(nums1, nums2) {
  let k = Math.floor((nums1.length + nums2.length - 1) / 2) // remove k elements
  const flag = (nums1.length + nums2.length + 1) % 2 // 1 indicates it is even
  if (nums1.length === 0) return flag === 1 ? (nums2[k]+nums2[k+1])/2 : nums2[k]
  if (nums2.length === 0) return flag === 1 ? (nums1[k]+nums1[k+1])/2 : nums1[k]
  if (nums1.length < nums2.length) [nums1, nums2] = [nums2, nums1]
  let b = k - nums2.length, e = k
  if (b < 0) b = 0
  while (e - b > 0) {
    let i1 = Math.floor((b+e)/2)
    let i2 = k - i1
    if (i2 !== nums2.length && nums1[i1-1] > nums2[i2]) {
      e = i1
    } else if (i2 !== 0 && nums2[i2-1] > nums1[i1]) {
      b = i1 + 1
    } else break;
  }
  let i1 = Math.floor((b+e)/2)
  let i2 = k - i1
  if (i2 === nums2.length) {
    return flag === 1 ? (nums1[i1]+nums1[i1+1])/2 : nums1[i1]
  } else if (flag === 0) {
    return nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2]
  } else {
    let rtn = nums1[i1] <= nums2[i2] ? nums1[i1++] : nums2[i2++]
    if (i2 === nums2.length) rtn += nums1[i1]
    else rtn += nums1[i1] < nums2[i2] ? nums1[i1] : nums2[i2]
    return rtn / 2
  }
};

var returnMininum = function(a1, a2, i1, i2) {

}

console.log(findMedianSortedArrays([1,2,3], [2]))
console.log(findMedianSortedArrays([1,3], [2]))
console.log(findMedianSortedArrays([1,2], [3]))
console.log(findMedianSortedArrays([2], [1]))
console.log(findMedianSortedArrays([1,2], [4,5,6]))
console.log(findMedianSortedArrays([1,3,5], [2,4,6]))
console.log(findMedianSortedArrays([1,3,5], [2,4]))
console.log(findMedianSortedArrays([1,3,5], [1,3,5]))
console.log(findMedianSortedArrays([1],[2,3,4,5,6,7]))
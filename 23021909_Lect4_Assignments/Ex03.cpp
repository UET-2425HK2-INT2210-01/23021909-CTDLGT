//Draw the 17-entry hash that results from using the hash function h(i) = (i+3) mod 17
//to hash keys 1, 3, 18, 8, 23, 35, 11, 36, 20, 16. 

//c) Assume collisions are handled by chaining. 
// h(1) = ( 1 + 3 ) mod 17 = 4
// h(3) = ( 3 + 3 ) mod 17 = 6
// h(18)= ( 18+ 3 ) mod 17 = 4
// h(8) = ( 8 + 3 ) mod 17 = 11
// h(23)= ( 23+ 3 ) mod 17 = 9
// h(35)= ( 35+ 3 ) mod 17 = 4
// h(11)= ( 11+ 3 ) mod 17 = 14
// h(36)= ( 36+ 3 ) mod 17 = 39 mod 17 = 5
// h(20)= ( 20+ 3 ) mod 17 = 23 mod 17 = 6
// h(16)= ( 16+ 3 ) mod 17 = 19 mod 17 = 2

// Vị trí                          Chaining
//   0                                
//   1                                
//   2                                16
//   3                                
//   4                                1-->18-->35
//   5                                36
//   6                                3-->20
//   7                                
//   8                                
//   9                                23
//  10                                
//  11                                8
//  12                                
//  13                                
//  14                                11
//  15                                
//  16                                

//d) Assume collisions are handled by linear probing. 

// h(1) = 4
// h(3) = 6
// h(18)= 4 (trùng =>vị trí 5)
// h(8) = 11
// h(23)= 9
// h(35)= 4 (trùng =>vị trí 7)
// h(11)= 14
// h(36)= 5 (trùng =>vị trí 8)
// h(20)= 6 (trùng =>vị trí 10)
// h(16)= 2

// Vị trí                       linear probing
//   0                                
//   1                                
//   2                                16
//   3                                
//   4                                1
//   5                                18
//   6                                3
//   7                                35
//   8                                36
//   9                                23
//  10                                20
//  11                                8
//  12                                
//  13                                
//  14                                11
//  15                                
//  16                                






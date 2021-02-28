fn main() {
    let s1 = String::from("hello");
    let len1 = calculate_length_v1(&s1);
    println!("The length of '{}' is {}", s1, len1); 

    // let s2 = String::from("hello");
    // let len2 = calculate_length_v2(s2);
    // println!("The length of '{}' is {}", s2, len2);

    let mut s3 = String::from("hello");
    let len3 = calculate_length_v3(&mut s3);
    println!("The length of '{}' is {}", s3, len3);

    // //不能同时拥有多个可变引用
    // let mut s4 = String::from("hello");
    // let r1 = &mut s4;
    // let r2 = &mut s4;
    // println!("{}, {}", r1, r2);

    // //可以同时拥有多个不可变引用
    // let s5 = String::from("hello");
    // let r3 = &s5;
    // let r4 = &s5;
    // println!("{}, {}", r3, r4);

    // //不能同时拥有可变引用和不可变引用
    // let mut s6 = String::from("hello");
    // let r5 = &mut s6;
    // let r6 = &s6;
    // println!("{}, {}", r5, r6);

    //引用的作用域
    //从声明开始到最后一次使用结束
    let mut s7 = String::from("hello");
    let r7 = &s7;
    let r8 = &s7;
    println!("{} and {}", r7, r8);

    let r9 = &mut s7;
    println!("{}", r9);

    // println!("{} and {}", r7, r8);   //加上这行代码会报错


    // //dangling reference
    // let reference_to_nothing = dangle_reference();
    // println!("")
}

fn calculate_length_v1(s: &String) -> usize {
    s.len()
}

// fn calculate_length_v2(s: String) -> usize {
//     s.len()
// }

fn calculate_length_v3(s: &mut String) -> usize {
    s.len()
}

// fn change(some_string: &String) {
//     some_string.push_str(", world!");    //不能修改引用指向的值
// }

// fn dangle_reference() -> &String {
//     let s = String::from("hello");
//     &s
// }   //注意s离开作用域后，它的内存被释放，返回的是一个悬垂引用

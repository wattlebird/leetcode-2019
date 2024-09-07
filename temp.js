var minimumString = function(a, b, c) {
    const foo = function(a, b) {
        if (a.includes(b)) return a;
        //starts with
        let rtn = a + b < b + a ? a + b : b + a;
        for(let i = 0; i < b.length; i++) {
            if (a.startsWith(b.slice(i))) {
                const tmp = b.slice(0, i) + a
                rtn = select(tmp, rtn)
                break;
            }
        }
        //ends with
        for(let i = b.length; i > 0; i--) {
            if (a.endsWith(b.slice(0, i))) {
                const tmp = a + b.slice(i)
                rtn = select(tmp, rtn)
                break;
            }
        }
        return rtn
    }

    const select = function(a, b) {
        let rtn = b
        if (a.length < rtn.length) rtn = a
        else if (a.length == rtn.length && a < rtn) rtn = a
        return rtn
    }
    
    let rtn = a + b + c
    let tmp = foo(foo(a, b), c)
    rtn = select(tmp, rtn)
    tmp = foo(foo(a, c), b)
    rtn = select(tmp, rtn)
    tmp = foo(foo(b, a), c)
    rtn = select(tmp, rtn)
    tmp = foo(foo(c, b), a)
    rtn = select(tmp, rtn)
    tmp = foo(foo(c, a), b)
    rtn = select(tmp, rtn)
    tmp = foo(foo(c, b), a)
    rtn = select(tmp, rtn)
    return rtn;
};

//console.log(longestValidSubstring("cbaaaabc", ["aaa","cb"]))
console.log(minimumString("hmlrrl","sh","hp"))
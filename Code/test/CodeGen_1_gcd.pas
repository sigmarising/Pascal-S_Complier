program example(input,output);
var 
    x,y,z : integer;
function gcd(a,b:integer) : integer;
    begin
        if a mod b = 0
            then gcd := b
            else gcd := gcd(b, a mod b)
    end;
begin
    read(x,y);
    write(gcd(x,y));
end.
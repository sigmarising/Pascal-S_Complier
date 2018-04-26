program selectsort(input, output);
var
    n, i : integer;
    a : array[1..100] of integer;
procedure ssort;
    var
        i, j, k, t : integer;
    begin
        for i := 1 to n - 1 do
            begin
                k := i;
                for j := i + 1 to n do
                    if a[j] < a[k] then k := j;
                
                if k <> i then
                    begin
                        t := a[i];
                        a[i] := a[k];
                        a[k] := t;
                    end;
            end;
    end;
begin
    readln(n);
    for i := 1 to n do
        read(a[i]);
    ssort;
    for i := 1 to n do
        writeln(a[i]);
    writeln;
end.

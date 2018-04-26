program quicksort(nothing);
var
    n, i : integer;
    a : array[0..100] of integer;
procedure qsort(l : integer ; r : integer);
    var
        i, j, k, t : integer;
    begin
        i := l;
        j := r;
        k := a[(i + j) div 2];
        while i <= j do
            begin
                while a[i] < k do i := i + 1;
                while a[j] > k do j := j - 1;
                if i <= j then
                    begin
                        t := a[i];
                        a[i] := a[j];
                        a[j] := t;
                        inc(i);
                        dec(j);
                    end;
            end;
        if l < j then qsort(l, j);
        if i < r then qsort(i, r);
    end;
begin
    readln(n);
    for i := 0 to n - 1 do
        read(a[i]);
    qsort(0, n - 1);
    for i := 0 to n - 1 do
        write(a[i], ' ');
    writeln();
end.
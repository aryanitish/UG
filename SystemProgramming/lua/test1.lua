print("Hello World")
--single line comment
--[[multiline 
comment 
]]
name = 'Nitish'
--another function to print on standard output. #var gives the size of var.
io.write("size of variable name  = ",#name,"\n")	

longString = [[ This is a very long String 
, so dont pay attention to it
]]

io.write("longString  = ",longString,"\n")
 
longString = longString .. name		--the '..' is the concatenation operator

io.write("longString  = ",longString,"\n")

io.write("longString type = ",type(longString),"\n")

months = {"January", "Februray", "March"}

for i,v in ipairs(months) do
	print("key = ", i,"value = ",v)
end





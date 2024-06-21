### KIEM DINH CHI BINH PHUONG

## KIEM TRA VE TINH DOC LAP CUA HAI BIEN

table(GT, KV)
# H0: GT va KV doc lap
# H1: GT va KV khong doc lap

chisq.test(table(GT, KV), correct = F)
# ko bac bo H0 => GT va KV doc lap
def escolhe_taxi(tf1,vqr1,tf2,vqr2):
    taxa1 = float(tf1)
    taxa2 = float(tf2)
    valor1 = float(vqr1)
    valor2 = float(vqr2)
    
    if taxa1 == taxa2 and valor1 == valor2:
        return "Tanto Faz"
    
    if taxa1 == taxa2:
        if valor1 > valor2:
            return "Empresa 2"
        else:
            return "Empresa 1"
    
    if valor1 == valor2:
        if taxa1 < taxa2:
            return "Empresa 1"
        else:
            return "Empresa 2"
    
    if taxa1 > taxa2 and valor1 > valor2:
        return "Empresa 2"
    
    if taxa2 > taxa1 and valor2 > valor1:
        return "Empresa 1"
        
    igual_em = (taxa2 - taxa1) / (valor1 - valor2)
    
    menor = ""
    maior = ""
    
    if taxa2 - taxa1 > 0:
        menor = 1
        maior = 2
    else:
        menor = 2
        maior = 1

    if igual_em.is_integer():
        return f"Empresa {menor} quando a distância < {igual_em:.1f}, Tanto faz quando a distância = {igual_em}, Empresa {maior} quando a distância > {igual_em}"

print(escolhe_taxi(2.5, 1.0, 5.0, 0.75))
print(escolhe_taxi(2, 1, 1, 3))

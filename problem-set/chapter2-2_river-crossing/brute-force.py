import numpy as np

dis_list = []

def time_accmulation(time:np.ndarray, status:np.ndarray, torch:bool, dis=0):
    
    if status.all() == 1:
        dis_list.append(dis)
        return
    

    if torch == 0:
        for i in range(len(status)):
            if status[i] == 0:
                for j in range(i+1, len(status)):
                    if status[j] == 0:

                        status_copy = status.copy()
                        status_copy[i] = 1
                        status_copy[j] = 1

                        time_accmulation(time, status_copy, 1, dis + max(time[i], time[j]))
                        
                
    if torch == 1:
        for i in range(len(status)):
            if status[i] == 1:
                
                status_copy = status.copy()
                status_copy[i] = 0

                time_accmulation(time, status_copy, 0, dis + time[i])



if __name__ == '__main__':
    time = np.array([1,2,5,10])
    status = np.zeros(4, dtype=bool)
    torch = 0

    time_accmulation(time, status, torch)

    print(dis_list)

    
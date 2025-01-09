def read_lines():
    N = int(input())
    lines = []
    for _ in range(N):
        x1, y1, x2, y2 = map(int, input().split())
        lines.append((x1, y1, x2, y2))
    K = int(input())
    return lines, K

def intersect_lines(lines):    
    intersection_map = {}    # Implement logic for identifying intersections and counting lines    
    return intersection_map
def calculate_intensity(intersection_map, K):    
    total_intensity = 0    
    for point, line_count in intersection_map.items():        
        if line_count == K:            # Calculate the intensity for this specific star            
            pass 
        # Replace with logic to calculate intensity    
        # return total_intensity
lines, K = read_lines()
intersection_map = intersect_lines(lines)
intensity_sum = calculate_intensity(intersection_map, K)
print(intensity_sum)

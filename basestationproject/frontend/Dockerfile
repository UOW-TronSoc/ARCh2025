FROM node:18-slim

WORKDIR /app

# Install dependencies
COPY package.json package-lock.json ./
RUN npm install

# Copy React app files
COPY . .

EXPOSE 3000

CMD ["npm", "start"]
